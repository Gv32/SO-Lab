#!/bin/bash

ps -aux | grep -ve "^root" | tr -s " " | cut -d " " -f 2,4 | grep -e "100|2[6-9]|[3-9][0-9]|25\.[1-9]" | cut -f 1 | kill -9