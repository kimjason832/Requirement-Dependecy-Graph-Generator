# Requirement-Dependecy-Graph-Generator

## Overview
    This program parses a given markdown file of an SRS to generate a requirement dependency graph and create a report of the requirement dependency graph. The requirement dependency graph shows the relationship between different requirements, where a parent requirement will branch out to a single or multiple child requirements. The requirement depdendency graph will be printed as a tree format starting with the highest requirement and continuously branching into its child requirements.

### Dependency
    The dependency module is used to create each moudle, or requirement of the SRS, and be linked together in a module list to show the relationships between different requirements as either a parent or a child. 
    The dependency module uses the following functions: 
        - createModuleList(): This creates a MODULE_LIST struct which holds a list of modules for dependent or depended on requirements
        - createModule(): This creates a MOUDLE struct holding the information of the requirement
        - appendModule(): This function adds a module into the module list struct while parsing through the SRS

### Parse
    The parse module is used to scan the given SRS and then print the requirement dependency graph.
    The parse module uses the following functions:
        - parseSRS(): This function gets the SRS file name and parses through the document to get and find relationships between the requirements
        - printDependencyList(): This function outputs in the requirement dependency graph all relationships between modules
        - printModule(): This function outputs a requirement and is to be used by printDependencyList()