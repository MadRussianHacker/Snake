# Snake clone by Michał Gibas

## Binary packages:

Windows (x86/x64): http://www.mediafire.com/file/6t74741uc1aumct/Snake_WIN.zip
OSX: (soon)

Linux users can easily build it (instructions below).

## Building

### Build dependencies

* Compiler with C++11 support (GCC, Visual C++, Clang)
* SDL 2.0 library
* GLM library

### Building on Linux:

1. Download or clone repository.
2. Open terminal.
3. Go to the folder with repository.
4. Create folder named "build":

```bash
    $ mkdir build
```

5. Open it (cd).
6. Type:

```bash
    $ cmake ..
    $ make
```
7. Your game is ready to play! To launch it type: ./snake ;)
