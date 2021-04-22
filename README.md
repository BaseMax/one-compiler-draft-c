# One-compiler Draft in C

Another attempt to write a compiler in c using flex and bison with all features of Syntax.

## Examples

```c
bool isOrNo {
	ret 0
}
float test {
	ret 5*5
}

testArg(i32 a, i32 b) {
}
demo(f32 abc){}
test{}
main(i32 a) {
	/*
	_ "hi"
	_ "hi" + "hi"
	_ 5
	_ 5+5
	_ 5.4
	i32 a
	f32 b
	a = 4
	b = 3.14
	// _ sin()
	sin(45)
	sin(45,180)
	//_ sin(45)
	//_ sin(45,180)
	//sin(45,180, sin(45))
	//sin(45,180, sin())
	*/
	i32 a = 0.45251 + 1
	i8 b = sin(45)
	sin(45, "hi")
	56
}
```

Another example:

```c
int z = 10
main(){
  str z = 'qq'
  if(true){
    int z= 8
    __z
  }
  __z
}

bool(){
  __z
}
```

## Next example

```c
home {
    _ "Hi, Welcome"
}
error {
    headers.add('HTTP/1.0 404 Not Found')
    headers.add('Content-Type: text/html; charset=utf-8')
    label {
        type: 'h1'
        _ "Not found!"
    }
}
main {
    _ "Star..."
    web.init()
    if system.args.length === 2 {
        port = system.args[1]
    } else  {
        port=8080;
    }
    routes {
        if 5 > 2 {
            /blog {
                home()
            }
        }
        else {
            /blog {
                _ "Hi"
            }
        }
        * {
            error()
        }
    }
    web.listen(port)
}
```

## Figures

![](figure1.jpg)

![](figure1.jpg)

Oh my god, I waste my time many days for a memory leaks:

![](figure3.jpg)

After solving the memory leaks:

![](figure4.jpg)

© Copyright Max Base 2020
