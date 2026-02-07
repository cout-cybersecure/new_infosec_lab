# INFOSEC LAB

## WHAT THIS DOES CURRENTLY

Implements fork, merge request, review, approvals, and protected branch rules for information security work. Converts merge request state into isolated environment instances, manages invitations, and handles workspace import/export as versioned packages.

**Components:**
- C++ library (`lib/`): VCS operations (fork, merge requests, reviews, approvals) and environment management (create from MR, invitations)
- Go CLI (`cli/`): Command-line interface for creating merge requests
- YAML config (`config/`): Branch protection rules
- Shell scripts (`scripts/`): Workspace package export/import and rule checking

## HOW TO USE

### BUILD

```bash
mkdir build && cd build
cmake ..
make
```

### CREATE MERGE REQUEST

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

### CHECK BRANCH PROTECTION RULES

```bash
./scripts/check_rules.sh <mr_id> [config_file]
```
## WHAT IS LEFT TO DO

- Set up infrastructure with secure boot, TPM, and disk encryption
- Configure immutable operating system (Fedora CoreOS or Talos Linux)
- Implement virtualization with KVM/QEMU and confidential computing support
- Configure network perimeter and segmentation with OPNsense
- Configure Kubernetes with containered and restricted runtime classes
- Configure Ceph storage with encryption for workspace data
- Configure Harbor registry with image signing and admission controls
- Implement secure workspace runtime isolation
- Implement policy enforcement with OPA Gatekeeper or Kyverno
- Configure network policies with Cilium and Envoy
- Integrate OpenBao for secrets management
- Set up WireGuard VPN and SSH certificate authority for remote access
- Configure Falco for runtime threat detection
- Set up telemetry stack (OpenTelemetry, Prometheus, Loki, Grafana)

