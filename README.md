# checkrc

The `checkrc` is a command-line tool designed to validate the configuration settings in the FreeBSD `/etc/rc.conf` file. This tool checks each setting against a predefined set of valid values to ensure that the configuration will function as expected when the system boots. The current way to debug errors in `/etc/rc.conf` if throught the shell command line `sh -n /etc/rc.conf && echo $?` for return error code in output. Horewer, this output is poor.

## Basic usage

To run `checkrc`, simply provide the path to the `rc.conf` file as an argument:

```bash
./checkrc /etc/rc.conf
```

## Expected Output


If everything goes as planned, the message will be as follows:

```bash
Config check passed successfully.
```
