# awk

An awk program is a sequence of patterns and corresponding
actions. When input is read that matches a pattern, the action
associated with that pattern is carried out.

```
awk '/pattern to be matched/ {action to be taken}' file_to_process.txt
```

awk can search multiple patterns and take different actions for *each
line* containing that pattern

```
awk '/pattern1/ {action 1}
/pattern 2/ {action2}'
```

A typical action is "print a field"

```
echo "hello world, folks" | awk '/hello/ {print $1}'
echo "hello world, folks" | awk '/hello/ {print $2}'
echo "hello world, folks" | awk '/hello/ {print $3}'
echo "hello world, folks" | awk '/hello/ {print NF}'
```

The default action is print the whole line

```
echo "hello world, folks" | awk '/hello/'
echo "hello world, folks" | awk '/hello/ {print $0}'
```

You can do a specifi action at *begin* and at the *end* of the
scanning of the file

```
awk 'BEGIN {action} /pattern/ {action} END {action}'
```

This is useful for actions involving variables

```
awk 'BEGIN {s=0} /Beth/ {s += 1} END {print s}' LittleWoman.txt
```

The default Field Separator is a space (or tab) but you can change it

```
echo "hello world, folks" | awk 'BEGIN{ FS="l"} /hello/ {print NF}'
```
## Warning

awk inside a bash script might behave differently than from command
line

# Exercise

Count the number of times that Beth, Jo, Amy and Meg are written
inside LittleWoman.txt.




