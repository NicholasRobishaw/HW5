#!/bin/bash
#SBATCH --job-name=hw5                               # the name of your job
#SBATCH --output=/scratch/nr768/INF-HW5/output.txt 
#SBATCH --error=/scratch/nr768/INF-HW5/errors.txt    # this is the file your output and errors go to
#SBATCH --time=12:00:00                               # 20 min, shorter time, quicker start, max run time
#SBATCH --chdir=/scratch/nr768/INF-HW5               # your work directory
#SBATCH --mem=10000                                  # 10GB of memory
#SBATCH --mail-type=FAIL


# Run your application: precede the application command with 'srun'
# A couple example applications...

srun ./my_program human.txt "1000000" 'B'