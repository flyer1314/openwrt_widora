#!/bin/bash

USER="fly"
#echo $USER
HOST="139.199.155.152"
#echo $HOST

FW_NAME="openwrt-ramips-mt7688-WIDORA32128-squashfs-sysupgrade.bin"

SRC_PWD="/home/fly/workspace/04-linkSmart7688/openwrt_widora/bin/ramips/"
DEST_PWD="./"

readonly USER HOST FW_NAME SRC_PWD DEST_PWD

#color debug
NONE="\e[0m"
RED="\e[31m"
GREEN="\e[32m"
YELLOW="\e[33m"
BLUE="\e[34m"

function FW_IsExist(){
    if [ -f $FW_NAME ];then
        echo -e ""$FW_NAME" is exist ."
        return 0
    else
        echo -e ""$FW_NAME" will download ."
        return 1
    fi
}

function DownloadFW(){ 
    FW_IsExist

    if [ $? -eq 0 ];then
        return 0
    else
        CMD_ALL=""$USER"@"$HOST":"$SRC_PWD""$FW_NAME"  "$DEST_PWD""
        echo $CMD_ALL
        scp $CMD_ALL
        return $?
    fi
}

function IsUpgrade(){
    read -t 30 -p "Whether to upgrade the firmware?(y/n):" retValue
    echo -e "\nInput:${RED}$retValue${NONE}"
    
    if [ ! $retValue ];then
        echo -e "${YELLOW}no input${NONE}"
        return 1
    elif [ $retValue =  "y" ];then
        echo -e "${GREEN}Will upgrade${NONE}"
        return 0
    elif [ $retValue = "n" ];then
        echo -e "${YELLOW}will not upgrade${NONE}"
        return 1
    else
        echo -e "${RED}input error${NONE}"
        return 1
    fi
}

function UpgradeFW(){
    IsUpgrade

    if [ $? -ne 0 ]; then
        echo -e "${YELLOW}no upgrade${NONE}"
        return 1
    else
        sysupgrade $FW_NAME
        if [ $? -eq 0 ];then
            echo -e "${GREEN}upgrade success${NONE}"
            return 0
        else
            echo -e "${RED}upgrade fail${NONE}"
            return 2
        fi
    fi
}

function main(){
    DownloadFW

    if [ $? -eq 0 ];then
        echo "Download firmware success, will upgrade firmware ......"
        UpgradeFW
        return 0
    else
        echo $CMD_ALL
        echo "Download firmware fail, will quit..."
        return 1
    fi
}

main

