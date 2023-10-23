#!/bin/bash

script_directory="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

chmod +x "./cpurunner.sh"
chmod +x "../build/CpuRunner"

export PATH="$PATH:$script_directory"
