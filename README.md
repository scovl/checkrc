# checkrc

The `checkrc` is a command-line tool designed to validate the configuration settings in the FreeBSD `/etc/rc.conf` file. This tool checks each setting against a predefined set of valid values to ensure that the configuration will function as expected when the system boots. The current way to debug errors in `/etc/rc.conf` if throught the shell command line `sh -n /etc/rc.conf && echo $?` for return error code in output. Horewer, this output is poor.

## Basic usage

To run `checkrc`, simply provide the path to the `rc.conf` file as an argument:

```bash
./checkrc /etc/rc.conf
```

<p align="center">
  <img src="https://raw.githubusercontent.com/scovl/checkrc/main/demo.gif" alt="checkrc GIF">
</p>


## Expected Output


If everything goes as planned, the message will be as follows:

```bash
Config check passed successfully.
```

## Contributing

Hey there! We're thrilled that you're interested in helping out with `checkrc`. Whether you're fixing bugs, adding new features, or just giving suggestions, your contribution is super valuable to me!

Here’s how you can get started:

1. **Fork the repository** on GitHub. This gets you a copy of the project to play around with on your own GitHub account.

2. **Clone your fork** to your local machine. Here’s the command you'll need:

   ```bash
   git clone https://github.com/scovl/checkrc.git
   ```

3. **Create a branch** for your changes. It’s best to keep your changes isolated in a specific branch:

   ```bash
   git checkout -b your-feature-branch
   ```

4. **Build the project** to see if everything works before you start making changes:

   ```bash
   gmake all
   ```
This command compiles and builds the entire project.

5. **Make your changes** and commit them:
   ```bash
   git add .
   git commit -m "Add some amazing feature"
   ```

6. **Clean your build** if you need to remove all compiled files before starting fresh:
   ```bash
   gmake clean
   ```
   Use this command to clean up the project directory, ensuring that no build artifacts or files are left behind.

7. **Push your branch** up to your fork:
   ```bash
   git push origin your-feature-branch
   ```

8. **Open a Pull Request** (PR) against the main `checkrc` repository. We'll look over your changes, maybe suggest some tweaks, and once everything looks good, we’ll merge them into the main project.

9. **Get feedback** and make any necessary tweaks to your submission based on our discussion.

10. **Celebrate** your contribution! Every little bit helps, and we're super grateful for your effort.

Don't worry if you're new to this or even if you’re facing some issues along the way; we're here to help! If you have any questions or need a bit of guidance, feel free to reach out by creating an issue in the repository or dropping us a message. Let’s make `checkrc` even better, together!

Thanks for being a part of our community!
