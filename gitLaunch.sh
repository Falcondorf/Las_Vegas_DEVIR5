#!/bin/bash

git add *
read -p "message de commit: " msg
git commit -m "$msg"
git push
echo "Appuyer sur entrée pour sortir"
read 