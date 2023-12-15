# Samp-incs
official repo of my SAMP includes

# Functions

* `ConvertStrToInt` - Convert a string to a Integer number.

* `StringSize` - Convert a string to a Integer number.

* `IsEqual` - Convert a string to a Integer number.

* `StrClone` - Convert a string to a Integer number.

# Examples

## `StrClone`

```cpp
new StrEx1[7];

StrClone(StrEx1[0], "Hello");

print(StrEx1[0]); //will output "Hello"
```

## `StringSize`

```cpp
new StrEx1[7];

StrClone(StrEx1[0], "Hello");

if(StringSize(StrEx[0]) == 5) 
{
	//this block will be executed
}
```

## `ConvertStrToInt`

```cpp
new StrEx1[3];

StrClone(StrEx1[0], "34");

if(ConvertStrToInt(StrEx[0]) == 34) 
{
	//this block will be executed
}
```

## `IsEqual`

```cpp
new StrEx1[7];
new StrEx2[7];

StrClone(StrEx1[0], "Hello");
StrClone(StrEx2[0], "Hello");

if(IsEqual(StrEx1[0], StrEx1[0])) 
{
	//this block will be executed
}
```
