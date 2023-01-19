# FORC

FORC stands for Find/Open/ReOpen/Clone, which is a common workflow if you are used to work with the nano editor.

## Install

Run the `install` script to copy the required scripts into your executable folder.

## Usage
Once it's installed, you can start using the `f` command from your working directory to find files that are deep inside the project structure:

```
f controller post
```

This will match any files that have the substrings "controller" and "post" in its path, in that order (case insensitive search).

This means you can just provide short substrings:

```
f cont pos
```


### Opening files

The `o` command works just like `f` but will attempt to open the file using nano.

```
o contr post
```

If more than one match is returned, it will not open anything and instead just show a list of files like `f` does.

It's up to you to improve the search criteria so that only one match is returned.

### Reopening / Resuming

If you are like me you will probably work on multiple files at the same time and use CTRL+z to leave a process behind and come back to it later.

Using `. r` is just like the `jobs` linux command, which lists currently suspended jobs:

```
> . r
[1]       o controller post
[2]       o view layout
```

Except it also allows you to search jobs by name:

```
. r post
```

If there is exactly one match, the job is then resumed (same as running `fg 2` in the example above)

I recommend aliasing `. r` to just `r` to make your life easier:

```
alias r='. r'
```

Now you can just, for example:

```
r layout
```

To resume the layout job.

### Cloning stuff

The `c` script simply clones a file into the same directory using a different name:

```
c layout2.html view layout
```

The example above finds a file with the "view layout" search criteria and creates `layout2.html` in the same directory it was found, copying the contents of the file into it.

Similarly to `o`, it will not create the file if there are multiple matches, and it's up to you to adjust your search until exactly only one file is returned.

There is a more intuitive syntax which combines the output of `f` with `c`:

```
f view layout | c layout2.html
```
