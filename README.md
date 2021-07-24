# Getting Started With Unreal

## Git

Download and install the Git command line extension. Once downloaded and installed, set up `Git LFS` for your user account by running:

```bash
git lfs install
```

You only need to run this once per user account.

In each Git repository where you want to use Git LFS, select the file types you'd like Git LFS to manage (or directly edit your `.gitattributes`). You can configure additional file extensions at anytime.

```bash
git lfs track "*.psd"
```

Now make sure '.gitattributes' is tracked:

```bash
git add .gitattributes
```

Note that defining the file types Git LFS should track will not, by itself, convert any pre-existing files to Git LFS, such as files on other branches or in your prior commit history. To do that, use the git lfs migrate command, which has a range of options designed to suit various potential use cases.

There is no step three. Just commit and push to GitHub as you normally would; for instance, if your current branch is named main:

```bash
git add file.psd
git commit -m "Add design file"
git push origin main
```

### Fixing files that should have been pointers in LFS but weren't

There is a relatively easy fix for a message from git lfs like:

`Encountered n file(s) that should have been pointers, but weren't`

If the files in question are already on a remote and you don't want to rewrite history, run:

```bash
git lfs migrate import --no-rewrite path/to/file.ext
```

This will create a new commit moving `path/to/file.ext` to LFS.

If you do need to rewrite history, see the documentation for migrating data to LFS.

To check whether this worked, run:

```bash
git lfs ls-files | grep path/to/file.ext
```

You should see an entry for `path/to/file.ext` in the resulting output.
