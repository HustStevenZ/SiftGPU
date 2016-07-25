#/usr/bin/env bash
IMAGE_DIR=$1
FILES=`ls -S -hr ${IMAGE_DIR}/*.jpg | tail -n 100`
SIFTCMD="./build/TestWinGlut"
rm time_consume.csv
touch time_consume.csv
for file in ${FILES}
do
    SIFTARG_FILE="-i  ${file} -o ${file}.sift"
    TIME_FILE=$(${SIFTCMD} ${SIFTARG_FILE} | grep "RUN SIFT"| sed -e "s/\[.*\]//")
    echo ${file} "${TIME_FILE}s">>time_consume.csv
done
echo "Batch processing is finished, plz backup the time_comsume.csv if it is necessary"
