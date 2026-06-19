# example-cpp-conan

> Find vulnerabilities, trace reachability, and audit open-source risk in your **C++** project.

## About

This repository is a [Bomly](https://bomly.dev) example project for **C++** with **Conan**.
Use it to try every Bomly feature — from basic SCA scans to vulnerability audits, reachability analysis, dependency tracing, and policy-driven CI gates.

## Dependency manifests

| File | Role |
|------|------|
| `conanfile.txt` | Dependency manifest |

## Try it with Bomly

### 1. Discover all dependencies

Map your full dependency graph — direct and transitive:

```bash
bomly scan --url https://github.com/bomly-dev/example-cpp-conan --ecosystems cpp
```

### 2. Find vulnerabilities

Enrich packages with CVE data and surface real findings:

```bash
bomly scan --url https://github.com/bomly-dev/example-cpp-conan --ecosystems cpp --enrich --audit
```

### 3. Trace why a dependency exists

Understand every path that pulls `openssl` into your graph:

```bash
bomly explain openssl --url https://github.com/bomly-dev/example-cpp-conan
```

### 4. See what changed between releases

Compare dependency graphs across any two refs - commits, branches, or tags:

```bash
bomly diff \
  --url https://github.com/bomly-dev/example-cpp-conan \
  --base v0.9.0 --head v1.0.0 \
  --enrich
```

### 5. Add a security gate to CI

Fail your pipeline automatically when high-severity vulnerabilities are introduced:

```yaml
# .github/workflows/bomly-guard.yml
name: Bomly Guard
on:
  pull_request:

permissions:
  contents: read
  pull-requests: write
  issues: write
  security-events: write

jobs:
  guard:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v5
        with:
          fetch-depth: 0
      # Add the package-manager setup steps this ecosystem needs before Bomly Guard.
      - uses: bomly-dev/bomly-guard@v1
        with:
          fail-on: high
          comment-summary-in-pr: always
```

Made with [Bomly](https://bomly.dev) — open-source SCA for every ecosystem.
