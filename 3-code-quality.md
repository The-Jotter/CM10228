---
title: Code Quality
date: 21-02-2023
---

# Code Quality
## Ideal Code
* Re-useable
* Resistant to bugs
* Optimised (to a degree) with appropriate code constructs
* Considered against other algorithms/implementations
* Documentation

### Maintainability
> How long can we deal with this code?

Maintainability is about how you can maintain the code
in the long term. What if the requirements change? Or if
all the programmers leave? 

Maintainability:
* Avoiding repetition &mdash; write DRY code (don't repeat yourself).
    
    Ideally, only change code in one place.

* Keeping the code simple &mdash; Keep it simple, stupid!
    
    Don't overcomplicate, and break down problems
    and functions if you have to.

    > You aren't gonna need it.

    Don't write more code than you have to &mdash; use version control!

* Encapsulation:

    Don't use global variables: you can't restrict access, and it leads to
    variable name clashes.

* Commenting:

    Comments should help anyone looking at the code to understand what/why
    the code does.

    Some pieces of code are trivial to understand, this kind of code are
    referred to as "self-documenting".

    Ideally, for strange codebases, perhaps consider explaining why the
    code does something.

* Code style:

    Some organisations have their own code style guidelines.

    Even programming languages have their own styles, for example:
    * Java prefers `camelCase` for variables; whereas
    * Rust prefers `snake_case` for variables;

    As long as it's consistent and has a logical structure,
    people will not care.

    *Naming conventions*:

    * `i`, `j`, `k` for loops
    * Descriptive parameter names.

    *Defensive programming*:

    This style of programming is about anticipating potential error states,
    or invalid inputs. It's about failing gracefully and recovering from them.

    You should: 

    * Avoid global variables (again)
    * Use `const` where things should not change.
    * Test the code!

### Efficiency
Optimise later, get it working first.