#!/bin/bash

# example of using arguments to a script
echo "Creating MPI Cluster for Random Decision Forest" 
echo "Installing general packages"

apt-get install cmake
apt-get install git



echo "Installing Boost Library" 
apt-get install libboost-all-dev

echo "Installing Boost Library" 
apt-get install mpich

#http://shaunharker.github.io/cluster-delegator/
echo "Installing Cluster Delegator Library" 
git clone https://github.com/shaunharker/cluster-delegator.git
cd cluster-delegator
./install.sh


echo "Configurating MPI Cluster"

echo "Adding nodes to host file (/etc/hosts)"
chmod 666 /etc/hosts 
echo "172.21.6.80 Node_1" >> /etc/hosts
echo "172.21.6.81 Node_2" >> /etc/hosts
echo "172.21.6.82 Node_3" >> /etc/hosts
echo "172.21.6.83 Node_4" >> /etc/hosts


echo "Configuring SSH" 
ssh-keygen -t rsa
ssh-copy-id Node_1
ssh-copy-id Node_2
ssh-copy-id Node_3
ssh-copy-id Node_4

eval `ssh-agent`
ssh-add ~/.ssh/id_dsa




echo "Configuring NFS" 

if [ "$1" = "master" ]
then
    echo "Configuring as Master"
    apt-get install nfs-server
    cd ../
    mkdir RDF
    echo "/home/manager/RDF *(rw,sync,no_root_squash,no_subtree_check)" >> /etc/exports
    exportfs -a
    service nfs-kernel-server restart
fi

if [ "$1" = "slave" ]
then
    echo "Configuring as Slave"
    apt-get install nfs-client
    apt-get install nfs-common
    cd ../
    mkdir RDF
    sudo mount -t nfs Node_1:/home/manager/RDF ~/RDF
    sudo mount -a   
    df -h
fi


echo "Your configuration was successfully"
