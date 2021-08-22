#!/usr/bin/env bash

# SPDX-License-Identifier: MIT

command_exists() {
    if ! command -v $1 &> /dev/null
    then
        echo "${1} could not be found"
        exit 1
    fi
}

commands_exists() {
    command_exists cmake
    command_exists gcc
}

build() {
    cmake -S . -B build/
    make -C build/
}

main() {
    commands_exists
    build
}

main
