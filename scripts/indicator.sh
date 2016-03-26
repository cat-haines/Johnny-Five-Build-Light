#!/usr/bin/env bash

curl -X POST https://api.particle.io/v1/devices/$PARTICLE_DEVICE_ID/setcolor \
  -d access_token=$PARTICLE_TOKEN \
  -d arg=$1