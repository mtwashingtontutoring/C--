# Git Cheat Sheet

## Every day

```
git status                     # What's changed? (run this constantly)
git add <file>                 # Stage a file for the next commit
git add .                      # Stage everything in this folder
git commit -m "<message>"      # Save a snapshot
git push                       # Upload commits to GitHub
git pull                       # Download commits from GitHub
```

## Looking around

```
git log --oneline              # Short history
git log --oneline --graph      # History with branch lines
git diff                       # Unstaged changes
git diff --staged              # Staged changes
git show <commit-id>           # What one commit changed
```

## Undoing

```
git restore <file>             # Throw away unsaved edits to a file (careful!)
git restore --staged <file>    # Unstage, but keep the edits
git commit --amend -m "<msg>"  # Fix the last commit message (before pushing)
git rm --cached <file>         # Stop tracking a file, keep it on disk
```

## Starting a project

```
git init                                    # New repo in current folder
git clone git@github.com:<user>/<repo>.git  # Copy a repo from GitHub
git remote add origin <url>                 # Connect a local repo to GitHub
git push -u origin main                     # First push
```

## One-time setup

```
git config --global user.name "<Your Name>"
git config --global user.email "<you@example.com>"
git config --global init.defaultBranch main
ssh-keygen -t ed25519 -C "<you@example.com>"
ssh -T git@github.com
```

## The workflow

```
  edit  -->  git add  -->  git commit  -->  git push
                                              |
  git pull  <---------------------------------+  (on another computer)
```
