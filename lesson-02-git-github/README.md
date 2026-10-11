# Lesson 2: Git and GitHub

## Goals

By the end of this lesson you will be able to:

1. Explain what version control is and why programmers use it.
2. Configure Git on your computer.
3. Create a repository, make commits, and view history.
4. Connect your computer to GitHub with an SSH key.
5. Push your code to GitHub and pull changes back down.
6. Use the Git features built into VSCodium.

---

## Part 1 - Why version control?

Ever had files like `essay.docx`, `essay_final.docx`,
`essay_final_REAL.docx`? Version control fixes that.

- **Git** is a program on your computer that takes *snapshots* of your project
  (called **commits**). You can look back at, compare, or restore any snapshot.
- **GitHub** is a website that stores copies of Git projects online so you can
  back them up, share them, and collaborate.

Git is the tool; GitHub is a place to host what the tool produces.

Key vocabulary:

| Term | Meaning |
|------|---------|
| **Repository (repo)** | A project folder that Git is tracking. |
| **Commit** | A saved snapshot of your files, with a message describing the change. |
| **Staging area** | The list of changes you've chosen to include in the *next* commit. |
| **Remote** | A copy of the repo somewhere else - usually on GitHub. |
| **Push** | Upload your commits to the remote. |
| **Pull** | Download new commits from the remote. |
| **Clone** | Download a complete copy of a remote repo. |

---

## Part 2 - Configure Git

Git was installed in Lesson 1. Confirm:

```
$ git --version
```

Tell Git who you are. This name and email are attached to every commit you
make. Use the **same email** you'll use for GitHub.

```
$ git config --global user.name "<Your Name>"
$ git config --global user.email "<you@example.com>"
$ git config --global init.defaultBranch main
$ git config --global core.editor "codium --wait"
```

Check your settings:

```
$ git config --global --list
```

> **Privacy tip:** If you don't want your real email to be public, after
> creating your GitHub account go to **Settings -> Emails**, enable
> *Keep my email addresses private*, and use the `...@users.noreply.github.com`
> address shown there as your `user.email`.

---

## Part 3 - Your first local repository

We'll turn last lesson's `hello` folder into a Git repository.

```
$ cd ~/cpp/hello
$ git init
$ git status
```

`git status` is the most useful Git command - run it often. Right now it shows
your files as **untracked** (Git sees them but isn't saving them yet).

### Ignore files that shouldn't be saved

The compiled `hello` executable can always be rebuilt from `hello.cpp`, so we
don't want it in the repo. Create a file named `.gitignore` containing:

```
# Compiled programs
hello
*.o
*.out
a.out
```

Run `git status` again - `hello` has disappeared from the list.

### Stage and commit

```
$ git add hello.cpp .gitignore
$ git status                       # files are now "staged" (green)
$ git commit -m "Add hello world program"
```

The workflow you'll repeat forever:

```
   edit files  -->  git add  -->  git commit
  (working dir)    (staging)     (history)
```

### Make a second commit

Edit `hello.cpp` to print a second line, e.g. your name. Then:

```
$ git status                       # hello.cpp is "modified"
$ git diff                         # see exactly what changed
$ git add hello.cpp
$ git commit -m "Print my name"
```

### Look at history

```
$ git log
$ git log --oneline
```

Each commit has a unique ID (a long hexadecimal *hash*, like `a1b2c3d`).

### Writing good commit messages

- Start with a verb in the present tense: *Add*, *Fix*, *Change*, *Remove*.
- Say **what** and, if not obvious, **why**.
- Good: `Fix triangle drawing one row too many`
- Bad: `stuff`, `asdf`, `final version`, `changes`

### Checkpoint 1

- [ ] `git log --oneline` shows at least two commits.
- [ ] `git status` says *nothing to commit, working tree clean*.

---

## Part 4 - Set up GitHub

### Create an account

Go to <https://github.com> and sign up. Choose a professional username - it
may end up on your resume.

### Create an SSH key

GitHub needs a way to know your computer is really you. An **SSH key** is a
pair of files: a *private* key that stays on your computer (never share it!)
and a *public* key you give to GitHub.

```
$ ssh-keygen -t ed25519 -C "<you@example.com>"
```

Press `Enter` to accept the default file location. You may set a passphrase
(recommended) or press `Enter` twice for none.

Display your **public** key:

```
$ cat ~/.ssh/id_ed25519.pub
```

Copy the entire line it prints (starts with `ssh-ed25519`).

On GitHub: click your profile picture -> **Settings** -> **SSH and GPG keys**
-> **New SSH key**. Give it a title like "Debian laptop", paste the key, and
save.

Test the connection:

```
$ ssh -T git@github.com
```

The first time, type `yes` to trust GitHub's server. Success looks like:

```
Hi <your-username>! You've successfully authenticated, but GitHub does not provide shell access.
```

> **Never** share or upload the file *without* `.pub` (`id_ed25519`). That's
> your private key - treat it like a password.

### Checkpoint 2

- [ ] `ssh -T git@github.com` greets you by username.

---

## Part 5 - Push your repo to GitHub

1. On GitHub, click **+** (top right) -> **New repository**.
2. Name it `cpp-hello`. Leave it **empty** - do *not* add a README,
   `.gitignore`, or license (you already have files locally).
3. Click **Create repository**.
4. On the next page, make sure **SSH** is selected and copy the URL - it looks
   like `git@github.com:<your-username>/cpp-hello.git`.

Back in the terminal:

```
$ git remote add origin git@github.com:<your-username>/cpp-hello.git
$ git push -u origin main
```

- `origin` is the conventional nickname for your main remote.
- `-u` remembers the connection, so from now on you can just type `git push`.

Refresh the GitHub page - your code is there!

### Checkpoint 3

- [ ] You can see `hello.cpp` and both commits on GitHub.

---

## Part 6 - Pull and clone

### Edit on GitHub, pull locally

1. On GitHub, click **Add a README** (or **Add file -> Create new file**,
   named `README.md`).
2. Write a sentence describing the project and click **Commit changes**.
3. Your computer doesn't have this commit yet. Get it:

   ```
   $ git pull
   $ ls                  # README.md is now here
   $ git log --oneline   # the new commit appears
   ```

### Clone a repository

Cloning downloads a full repo, history and all:

```
$ cd ~/cpp
$ git clone git@github.com:<your-username>/cpp-hello.git hello-copy
$ cd hello-copy
$ git log --oneline
```

This is how you'll get a project onto a new computer.

---

## Part 7 - Git inside VSCodium

Everything above can also be done with buttons. Open your `hello` folder in
VSCodium and click the **Source Control** icon (branch shape on the left bar,
or `Ctrl` + `Shift` + `G`).

- Changed files appear in a list. Click one to see a side-by-side diff.
- Click **+** next to a file to stage it (`git add`).
- Type a message in the box and click **Commit** (`git commit`).
- Click **Sync Changes** to pull and push.

The terminal and the buttons do the same thing - use whichever you like, but
make sure you understand the commands, because the terminal is what you'll
reach for when something goes wrong.

---

## Part 8 - Setting up your class repository

For the rest of the course, keep all your work in **one** repository:

```
$ cd ~/cpp
$ mkdir intro-cpp && cd intro-cpp
$ git init
```

Create this `.gitignore`:

```
# Compiled executables (files with no extension)
*
!*/
!*.*
!.gitignore

# Object files and editor junk
*.o
*.out
.vscode/ipch/
```

> The first four lines say "ignore everything, except folders, files that have
> a dot in their name, and `.gitignore` itself". On Linux, compiled programs
> usually have no extension, so this keeps them out of your repo
> automatically.

Then create a folder for each lesson as you go (`lesson-01`, `lesson-02`,
...), commit often, and push to a GitHub repo named `intro-cpp`. Add your
instructor as a collaborator if asked: **Settings -> Collaborators -> Add
people**.

---

## Exercises

1. **Commit early, commit often.** Copy your Lesson 1 exercises into
   `intro-cpp/lesson-01/`. Commit *each exercise separately* with a clear
   message. Push. Your GitHub history should show one commit per exercise.
2. **Time travel.** Run `git log --oneline`, pick an older commit ID, and run
   `git show <id>`. What changed in that commit? Then try
   `git diff <older-id> <newer-id>`.
3. **Undo a mistake.** Edit a file and save it with nonsense. Before
   committing, run `git restore <file>`. What happened?
4. **Unstage.** Edit a file, `git add` it, then run `git restore --staged
   <file>`. Check `git status` before and after.
5. **Write a README.** Add a `README.md` to `intro-cpp` with your name, the
   course name, and a list of lessons. Use Markdown: `#` for headings, `-`
   for bullets. Commit and push, then view it on GitHub.

## Common problems

| Problem | Fix |
|---------|-----|
| `Permission denied (publickey)` | Your SSH key isn't set up. Redo Part 4 and check you pasted the `.pub` file. |
| `fatal: not a git repository` | You're in the wrong folder. `cd` into your project, or run `git init`. |
| `rejected ... (fetch first)` when pushing | GitHub has commits you don't. Run `git pull`, then `git push`. |
| `remote origin already exists` | Use `git remote set-url origin <url>` instead of `add`. |
| Committed the `hello` executable by accident | Add it to `.gitignore`, run `git rm --cached hello`, then commit. |
| An editor opened and you're stuck | You ran `git commit` without `-m`. Type a message on the first line, save, and close the tab. |

See [`cheatsheet.md`](cheatsheet.md) for a one-page reference.
