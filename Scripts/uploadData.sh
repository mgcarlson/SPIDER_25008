#!bin/sh

echo "in script now"
curr_dir=$(pwd)
echo $curr_dir
cd ../../
cd SPIDER_Data
git add .
git commit -m "saving data"
git push
rm -r testData/*
cd $curr_dir
echo "changes pushed to github"
