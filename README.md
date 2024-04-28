# checkrc

The `checkrc` tool ia a command-line tool designed to validate the configuration settings in the FreeBSD `/etc/rc.conf` file. This tool checks each setting against a predefined set of valid values to ensure that the configuration will function as expected when the system boots.


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
