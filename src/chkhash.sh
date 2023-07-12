#!/bin/bash

    
main() {
    # place stuff you want to run here
    echo "hello world!"
    if [ "$(<c_string_gcc.sha256 sha256sum)" = "$(<c_string_zig.sha256 sha256sum)" ]; then
        echo '[OK] hashes match'
    else
        echo '[WARN] hashes do not match'
    fi
}

main
