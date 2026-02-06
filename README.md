# Infosec Lab

## What This Does

Implements fork, merge request, review, approvals, and protected branch rules for information security work. Converts merge request state into isolated environment instances, manages invitations, and handles workspace import/export as versioned bundles.

**Components:**
- C++ library (`lib/`): VCS operations (fork, merge requests, reviews, approvals) and environment management (create from MR, invitations)
- Go CLI (`cli/`): Command-line interface for creating merge requests
- YAML config (`config/`): Branch protection rules
- Shell scripts (`scripts/`): Workspace bundle export/import and rule checking

## How to Use

### Build

```bash
mkdir build && cd build
cmake ..
make
```

### Create Merge Request

```bash
cd cli
go build -o infosec-cli main.go
./infosec-cli -action create-mr -config /path/to/config.json
```

Config JSON format:
```json
{
  "source_branch": "feature-branch",
  "target_branch": "main",
  "title": "MR Title",
  "author": "user@example.com",
  "reviewers": ["reviewer1", "reviewer2"]
}
```

### Check Branch Protection Rules

```bash
./scripts/check_rules.sh <mr_id> [config_file]
```
