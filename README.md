# minitalk
## Rules
There are two programs: ```client``` and ```server```

```client``` sends a messege in binary code to ```server``` by using signals: ```SIGUSR1``` for ```1``` and ```SIGUSR2``` for ```0```

The program supports unicode symbols.
## Usage
To compile both programs you should do ```make``` and then execute 
```
./server
```
In another window do
```
./client <output of server> <messege>
```
