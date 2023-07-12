`/dev/random` is a file that represents an infinite stream of random bytes. You can use it if you want something better than a PRNG. It may not be "truly random" though but it's still an improvement.

```sh
# write n random bytes to a file 
head --bytes <n> /dev/urandom > random.bytes
```