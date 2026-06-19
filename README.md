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

### 4. Add a security gate to CI

Fail your pipeline automatically when high-severity vulnerabilities are introduced:

```yaml
# .github/workflows/bomly.yml
name: Bomly Security Scan
on: [push, pull_request]

jobs:
  scan:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v4
      - name: Scan with Bomly
        run: |
          curl -sSfL https://bomly.dev/install.sh | sh
          bomly scan --enrich --audit --fail-on high
```

Made with [Bomly](https://bomly.dev) — open-source SCA for every ecosystem.
