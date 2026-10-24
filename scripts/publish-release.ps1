[CmdletBinding()]
param(
    [Parameter(Mandatory = $true, Position = 0)]
    [string]$Version
)

Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'

if ($Version -notmatch '^v\d+\.\d+(?:\.\d+)?$') {
    throw "버전은 v1.16 또는 v1.16.1 형식이어야 합니다: $Version"
}

$repoRoot = Split-Path -Parent $PSScriptRoot
Push-Location $repoRoot

try {
    $insideWorkTree = git rev-parse --is-inside-work-tree 2>$null
    if ($LASTEXITCODE -ne 0 -or $insideWorkTree -ne 'true') {
        throw 'Git 저장소를 확인할 수 없습니다.'
    }

    $branch = git branch --show-current
    if ($LASTEXITCODE -ne 0 -or $branch -ne 'main') {
        throw "main 브랜치에서 실행해야 합니다. 현재 브랜치: $branch"
    }

    $changes = git status --porcelain
    if ($LASTEXITCODE -ne 0) {
        throw 'Git 작업 트리 상태를 확인하지 못했습니다.'
    }
    if ($changes) {
        throw '커밋되지 않은 변경이 있습니다. 먼저 변경을 커밋하세요.'
    }

    git fetch origin main --quiet
    if ($LASTEXITCODE -ne 0) {
        throw 'origin/main을 가져오지 못했습니다.'
    }

    $head = git rev-parse HEAD
    $originMain = git rev-parse origin/main
    if ($head -ne $originMain) {
        throw '현재 커밋과 origin/main이 다릅니다. main 푸시 또는 동기화를 먼저 완료하세요.'
    }

    $localTag = git tag --list $Version
    if ($localTag) {
        throw "로컬 태그가 이미 존재합니다: $Version"
    }

    git ls-remote --exit-code --tags origin "refs/tags/$Version" *> $null
    if ($LASTEXITCODE -eq 0) {
        throw "원격 태그가 이미 존재합니다: $Version"
    }
    if ($LASTEXITCODE -ne 2) {
        throw '원격 태그 존재 여부를 확인하지 못했습니다.'
    }

    $readme = Get-Content -Raw -Encoding UTF8 README.md
    if (-not $readme.Contains("배포 버전: $Version.")) {
        throw "README.md의 배포 버전이 $Version 태그와 일치하지 않습니다."
    }

    $agents = Get-Content -Raw -Encoding UTF8 AGENTS.md
    if (-not ($agents.Contains('현재 배포 버전은') -and $agents.Contains($Version))) {
        throw "AGENTS.md의 배포 버전이 $Version 태그와 일치하지 않습니다."
    }

    git tag -a $Version -m "KakoMVP $Version"
    if ($LASTEXITCODE -ne 0) {
        throw "태그를 생성하지 못했습니다: $Version"
    }

    git push origin "refs/tags/$Version"
    if ($LASTEXITCODE -ne 0) {
        git tag -d $Version *> $null
        throw "태그 푸시에 실패했습니다. 생성한 로컬 태그를 제거했습니다: $Version"
    }

    Write-Host "태그 $Version 푸시를 완료했습니다."
    Write-Host 'GitHub Actions가 Windows x64 EXE를 빌드하고 Release에 첨부합니다.'
    Write-Host '진행 상태: https://github.com/resumet/kakao-opentalk-manager/actions'
}
finally {
    Pop-Location
}
