# Exercise 2

## Sed

```
$ man sed
sed - stream editor for filtering and transforming text
```

Stream EDditor. It is simple to use for simple applications and
features a rich set of commands for complex applications. We will see
few of them

## Substitution *s* `sed s/pattern_to_find/replacement/`
```
$ echo day > old
$ sed 's/day/night/' old > new
$ cat new
```
```
$ echo day | sed s/day/night/ 
```


Try yourself to modify the file `haiku.txt`

Sed replace only **the first** pattern per line. To replace **all** occurrencies add a `g`. To replace the **n**-th matched one, add the number
```
$ sed 's/s/SSS/' haiku.txt
$ sed 's/s/SSS/g' haiku.txt
$ sed 's/s/SSS/2' haiku.txt
```


`&` corresponds to the pattern matched. This is useful when combined
  with regular expressions

```
sed 's/[Aa-Zz]*day/--- & ---/' haiku.txt
```


Delete the first line or the last one.
```
$ sed '1 d'
$ sed '$ d'
```

Delete a line matching a given pattern

```
$ sed '/day/d'
```

Much more...

	      
## One-liners

One-liners are combination of some (many) bash commands written on one
line to achieve a specific task in a very efficient way. In the
following, we report some useful examples. We invite you to try them
and understan how and why they work. Then, you could challenge
yourself in finding a one-liner to achieve the same result.

- Find how many processors a computer (node) has:
```
$ cat /proc/cpuinfo | grep 'processor' | wc -l
$ cat /proc/cpuinfo | grep 'processor' | cut -d : -f 2 | sort | tail -n1 | xargs sh -c 'c=$1; let "c+=1"; echo $c' sh
```

- Print the model name of the processors:
```
$ cat /proc/cpuinfo | grep 'model name' | uniq | cut -d : -f 2
```

- Count the physical processors
```
$ cat /proc/cpuinfo | grep 'core id' | sort | uniq | wc -l
$ cat /proc/cpuinfo | grep 'core id' | sort | uniq -c
```

- Change the numbering
```
$ cat /proc/cpuinfo |  sed -r 's/(processor)(.*)([0-9]+)/echo "\1\2$((\3+1))"/ge'
```

## Exercises

1. Find the 5 largest file inside one directory (and subdirectories of course)

2. Find the 10 most used commands on ~/.bash_history
