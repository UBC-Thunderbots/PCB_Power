# PCB_Power Description
Github SVN repository for UBC Thunderbots PCB_Power Altium project files. 

# How to link repository with Altium Designer
## Required software
1. git
2. github GUI (optional, I am using GitHub Desktop)
2. Altium Designer

## Instructions
1. Create a working branch of Master in github.
1. Clone your working branch of the UBC-Thunderbots/PCB_Power repo to your PC (i.e. C:/Documents/GitHub/PCB_Power)
2. In Altium Designer, navigate to **Preferences** -> **Data Management** -> **Version Control** and ensure *SVN - Subversion* is enabled and Version 1.9 is selected.
4. In Altium Designer, navigate to **Preferences** -> **Data Management** -> **Design Repositories**.
5. Within **Design Repositories** click on on *Connect To* -> *SVN*.
6. In the dialogue box that comes up, fill in the following information:

Field | Selection/Input
--- | ---
Name | PCB_Power
Default Checkout Path | *location of the cloned UBC-Thunderbots/PCB_MotorDriver repository (i.e. C:/Documents/GitHub/PCB_Power)*
Method | https
Server | github.com
Server Port | Default
Repository Subfolder | /UBC-Thunderbots/PCB_Power
User Name | *your github login username*
Password | *your github login password*

7. Click *Test* and pray.
8. Celebrate!

After your repository is connected, you can add or remove files like a regular Altium Project folder and then commit them from within Altium Designer by right-clicking on any project files in the **Projects** and hovering the mouse cursor over **Version Control**.

Reference page: https://forum.live.altium.com/#posts/235981/718003

# Repository Structure

At the highest level, there should be the most up to date board revisions, e.g.
`power-v2.0/`. Any previous versions should be placed in `archive/`. Every board revision directory should abide by the following structure:

```
<name-v#>/
├── doc/
│   ├── <name>.pdf
│   └── <name>.xslx or <name>.csv
├── pcb/
│   ├── <name>.PrjPCB
│   ├── <name>.SchDoc
│   └── <name>.PcbDoc
├── sim/
```

## doc/
For documentation and relevant non-simulation and layout files. This includes PDFs of the design and bills of materials (`*.xlsx` or `.csv` format). This also includes schematic and PCB layout guidelines.

## pcb/
For any PCB design software files related to the schematic capture and PCB layout of board. 

## sim/
For any simulation files related to the PCB design here. 