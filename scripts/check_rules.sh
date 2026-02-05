#!/bin/bash

MR_ID="$1"
CONFIG="${2:-config/branch_protection.yaml}"

if [ ! -f "$CONFIG" ]; then
    echo "Config file not found: $CONFIG" >&2
    exit 1
fi

if [ ! -f "data/vcs/${MR_ID}.json" ]; then
    echo "Merge request not found: $MR_ID" >&2
    exit 1
fi

TARGET_BRANCH=$(grep -o '"target":"[^"]*"' "data/vcs/${MR_ID}.json" | cut -d'"' -f4)

if grep -q "branch:.*${TARGET_BRANCH}" "$CONFIG" || grep -q "branch_pattern:.*${TARGET_BRANCH}" "$CONFIG"; then
    echo "Branch protection rules apply"
    exit 0
else
    echo "No protection rules for branch: $TARGET_BRANCH"
    exit 1
fi
