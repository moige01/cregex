# CRegex

## Table of Contents

- [About](#about)
- [Usage](#usage)
- [Contributing](../CONTRIBUTING.md)

## About <a name = "about"></a>

This is just a going in deeper to learn about RegexEngines. This is a part of a series of projects to learn in deeper about multiples technologies.

### Prerequisites

GCC and CMake

### Installing

```sh
$ ./build.sh
$ ./build/cregex "." "test"
```

## Usage <a name = "usage"></a>

```sh
$ ./build/cregex "w*" "works"
$ Match!
$ ./build/cregex "x*" "works"
$ Oops!
```
