[CmdletBinding()]
param(
    [Parameter(Mandatory = $true, Position = 0)]
    [string]$Version
)

Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'

if ($Version -notmatch '^v\d+\.\d+(?:\.\d+)?$') {
    throw "Version must use a format such as v1.16 or v1.16.1: $Version"
}

$repoRoot = Split-Path -Parent $PSScriptRoot
Push-Location $repoRoot

try {
    $insideWorkTree = git rev-parse --is-inside-work-tree 2>$null
    if ($LASTEXITCODE -ne 0 -or $insideWorkTree -ne 'true') {
        throw 'The Git repository could not be verified.'
    }

    $branch = git branch --show-current
    if ($LASTEXITCODE -ne 0 -or $branch -ne 'main') {
        throw "Run this script on the main branch. Current branch: $branch"
    }

    $changes = git status --porcelain
    if ($LASTEXITCODE -ne 0) {
        throw 'The Git working tree could not be inspected.'
    }
    if ($changes) {
        throw 'The working tree has uncommitted changes. Commit them first.'
    }

    git fetch origin main --quiet
    if ($LASTEXITCODE -ne 0) {
        throw 'Fetching origin/main failed.'
    }

    $head = git rev-parse HEAD
    $originMain = git rev-parse origin/main
    if ($head -ne $originMain) {
        throw 'HEAD differs from origin/main. Push or synchronize main first.'
    }

    $localTag = git tag --list $Version
    if ($localTag) {
        throw "The local tag already exists: $Version"
    }

    git ls-remote --exit-code --tags origin "refs/tags/$Version" *> $null
    if ($LASTEXITCODE -eq 0) {
        throw "The remote tag already exists: $Version"
    }
    if ($LASTEXITCODE -ne 2) {
        throw 'The remote tag could not be checked.'
    }

    $readmeHeader = (Get-Content -Encoding UTF8 README.md -TotalCount 5) -join "`n"
    if (-not $readmeHeader.Contains($Version)) {
        throw "The README.md header does not declare release version $Version."
    }

    $agents = Get-Content -Raw -Encoding UTF8 AGENTS.md
    if (-not $agents.Contains($Version)) {
        throw "AGENTS.md does not declare release version $Version."
    }

    git tag -a $Version -m "KakoMVP $Version"
    if ($LASTEXITCODE -ne 0) {
        throw "Creating the tag failed: $Version"
    }

    git push origin "refs/tags/$Version"
    if ($LASTEXITCODE -ne 0) {
        git tag -d $Version *> $null
        throw "Pushing the tag failed. The new local tag was removed: $Version"
    }

    Write-Host "Tag $Version was pushed."
    Write-Host 'GitHub Actions will build the Windows x64 EXE and attach it to the Release.'
    Write-Host 'Progress: https://github.com/resumet/kakao-opentalk-manager/actions'
}
finally {
    Pop-Location
}
