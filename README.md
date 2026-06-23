# PeParser

A small Windows PE (Portable Executable) file parser written in C++.

## What it does

Reads a `.exe` or `.dll` file and parses its headers directly from the raw
bytes, printing:

- **DOS header** — bytes on last page, pages in file, header size, file
  address of the relocation table, file address of the NT headers
- **NT file header** — target machine architecture (x86/AMD64), number of
  sections, compiler timestamp, size of the optional header, image
  characteristics flags

It checks the DOS signature (`MZ` / `IMAGE_DOS_SIGNATURE`) before parsing
anything, so it won't try to read a file that isn't actually a PE binary.

## Build

Windows only — uses `<windows.h>` / `<winnt.h>` for the PE header structs.

```bash
cmake -G Ninja -B build
ninja -C build
```

## Usage

```bash
PeParser.exe path\to\file.exe
```

## Files

| File | Purpose |
|---|---|
| `parse.h` / `parse.cpp` | DOS + NT header parsing |
| `Colors.h` | Terminal color output helpers |
| `main.cpp` | Entry point |
