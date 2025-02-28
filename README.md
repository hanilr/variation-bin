# <center> <img src="img/vn_blue.png"> Variation: Binary <img src="img/vn_blue.png"> </center>

Variation Binary is single-header binary analysis library. Written in Ansi-c which means `c89` standard version. 

> Libraries are written in the ANSI-C standard because the user must be able to use them both in the C89 standard and in higher standards.

<img src="img/vn_info.png"> Dependencies <img src="img/vn_info.png">

* `gcc` _> Gnu Compiler Collection_

* `make` _> Gnu Make_

> In Windows, you should have mingw and gnu make programs. In Linux, you can install easly in teminal via package managers.

### <img src="img/vn_warn.png"> Important Note <img src="img/vn_warn.png">

You need to define `#define VN_BIN_IMPLEMENTATION` before `#include "vn_bin.h"`

```c
#define VN_BIN_IMPLEMENTATION
#include "vn_bin.h"
```

If you installed the library then you should do like this.

```c
#include <vn/vn_bin.h>
```

> You can see examples in `demo/` folder.

### <img src="img/vn_example.png"> Example <img src="img/vn_example.png">

```c
#include <stdio.h>

#define VN_BIN_IMPLEMENTATION
#include "vn_bin.h"

int main(void) {
    enum Bin_S S_4 = 4;
    enum Bin_S S_8 = 8;
    enum Bin_S S_16 = 16;
    enum Bin_S S_32 = 32;
    enum Bin_S S_64 = 64;
    enum Bin_S S_128 = 128;

    struct Bin_T Bin[6];
    int num[6] = {3, 7, 15, 31, 63, 127};

    Bin[0] = vn_int_to_bin(S_4, num[0]);
    Bin[1] = vn_int_to_bin(S_8, num[1]);
    Bin[2] = vn_int_to_bin(S_16, num[2]);
    Bin[3] = vn_int_to_bin(S_32, num[3]);
    Bin[4] = vn_int_to_bin(S_64, num[4]);
    Bin[5] = vn_int_to_bin(S_128, num[5]);

    bin_print(S_4, Bin[0]);
    bin_print(S_8, Bin[1]);
    bin_print(S_16, Bin[2]);
    bin_print(S_32, Bin[3]);
    bin_print(S_64, Bin[4]);
    bin_print(S_128, Bin[5]);

    return 0;
}
```

### <img src="img/vn_green.png"> Shared-Library and Default-Library <img src="img/vn_green.png">

> Show make list with `make` or `make run` commands.

```bash
make run
```

<img src="img/vn_red.png"> Compile as Shared-Library <img src="img/vn_red.png">

```bash
make compile
```

> This command only compile as `.so` and its for Linux only.

> You can clean compile files with this command.
> ```bash 
> make clean
> ```

<img src="img/vn_blue.png"> Using as Default Library  <img src="img/vn_blue.png">

```bash
make install
```

> You can find in /usr/include/vn/

> You can uninstall with this command.
> ```bash
> make uninstall
> ```

<img src="img/vn_wiki.png"> You can take a look to wiki page if you want learn more <img src="img/vn_warn.png">

#### Check Other Variation Libraries

* [Variation: User Interface](https://github.com/hanilr/variation-ui) - A terminal user interface in Ansi-C with widgets.

* [Variation Lite: User Interface](https://github.com/hanilr/variation-lite-ui) - A terminal user interface in Ansi-C with optimize code and no widgets.