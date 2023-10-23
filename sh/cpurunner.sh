#!/bin/bash

script_directory="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

echo "$script_directory"

# Which I wanna run program
$script_directory/../build/CpuRunner
