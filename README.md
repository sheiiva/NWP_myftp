my_ftp
===

Time:       3 weeks

Team:       1

Language:   C


The project
----
The goal of this project is to create a [**FTP server**](https://fr.wikipedia.org/wiki/File_Transfer_Protocol).
You MUST implement the given protocol (bonuses must be RFC959 compliant).
You MUST implement request sequences that are explained in the protocol (more information could befind in RFC959).The network communication will be achieved through the use of TCP sockets.


## USAGE:

```
>> make
>> ./myftp –help
USAGE: ./myftp port path
    port              the port number on which the server socket listens
    path              the path to the home directory for the Anonymous user
```

##### WARNING
The server MUST be able to handle several clients at the same time by using `select` for command manage-ment and `fork` for data transfer.
The server MUST have an authentication with an **Anonymous account** and an **empty password**. Data transfers MUST use **active** or **passive** mode.


## TESTS

```
>> make tests_run
``` 

 > other rules: `make fclean`, `make clean`, `make re`


Author [**Corentin COUTRET-ROZET**](https://github.com/sheiiva)
