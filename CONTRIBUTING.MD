# Contributing to BEIT Notes

Thanks for wanting to help. This repo works best when notes from more people are collected in one place, so contributions are welcome.

## What to contribute

- Class notes, slides, or summaries for a subject
- Solved question papers or model answers
- Lab code and lab reports
- Corrections to existing notes (typos, wrong answers, outdated syllabus references)

Please don't upload full copyrighted textbooks. Linking to where a book can be found is fine; re-uploading the whole book is not.

## Folder structure

Files are organised as:

```
sem-0X/COURSE-CODE-subject-name/
```

For example, notes for Computer Networks in semester 6 go in:

```
sem-06/CMP-344-computer-network/
```

Inside a subject folder, group files like this if there's more than a couple of them:

```
sem-06/CMP-344-computer-network/
├── notes/
├── labs/
├── question-papers/
└── syllabus/
```

If the subject folder doesn't exist yet, create it using the same `CODE-subject-name` pattern (lowercase, hyphens instead of spaces). Check the [Course Structure](readme.md#course-structure) table in the README for the correct course code.

## How to contribute

1. **Fork** this repository.
2. **Create a branch** for your change:
   ```bash
   git checkout -b add-cmp344-notes
   ```
3. **Add your files** to the correct semester/subject folder, following the structure above.
4. **Commit** with a clear message describing what you added:
   ```bash
   git commit -m "Add CMP 344 unit 3 notes"
   ```
5. **Push** your branch and open a **pull request** against `main`.
6. In the pull request description, mention the subject and semester, and note if it's new content or a correction.

## File guidelines

- Prefer PDF for notes and scanned material.
- Keep filenames descriptive, e.g. `Unit-3-Transport-Layer.pdf` rather than `notes1.pdf` or `IMG_2024.pdf`.
- Avoid duplicate uploads — check the subject folder first to see if similar content already exists.
- Don't commit junk files such as `.DS_Store`, IDE settings, or temporary build files.

## Requesting notes

If you're looking for notes on a subject that isn't here yet, open an [issue](https://github.com/SurajKumarJha465/BEIT-notes-/issues) describing the subject and semester. Someone with those notes may pick it up.

## Code of conduct

Be respectful. This is a shared resource for students — no spam, no unrelated content, no plagiarised material without credit.