# Better String

A C library that provides a better string that resizes its size automatically.

## Getting started

Simply download `better_string.h` and put it in your source code.
The project is licensed under the MIT license.

Or, to quickly test it out, we have a simple test program:

```bash
gcc test.c
./a.out
```

## Basic usage

Make sure you have included the downloaded header!

To create a new string:

```c
string* my_str = str_init();
if (my_str == NULL) puts("alloc failed");
str_add(my_str, "Hello World!");
```

You will often need to turn a string into a C string.
For this case, you can use the `c_str()` function:

```c
puts(c_str(my_str));
```

A string is simply a struct with an integer holding its size and
a C string with the raw data.

After you are finished working with your string, you MUST use the
`str_free()` function to free allocated memory:

```c
str_free(my_str);
```

This automatically frees `my_str->data` and `my_str`.

## Other functions

### `str_addc()`

This is what `str_add` uses under the hood. This function simply
resizes your string with `realloc`, moves the null terminator and
puts the character before the null terminator.

```c
str_addc(my_string, 'h');
```

### `c_str_to_str()`

Turns a C string into a string. *(why are we calling these "the" strings, again?)*

```c
const char *path = getenv("PATH");
string* new_string = c_str_to_str(path);
```

### `char_to_str()`

Turns a character into a string.

```c
char ch = (char)getchar();
string* str_from_char = char_to_str(ch);
```

### `str_len()`

Just runs `strlen()` from `<string.h>` on `string->data`.
