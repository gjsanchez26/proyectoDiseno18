
#!/bin/bash

# example of using arguments to a script
echo "Creating MPI Cluster for Random Decision Forest" 
if [ "$1" = "client" ]
then
    echo "Configuring as Master"
    
fi

if [ "$1" = "server" ]
then
    echo "Configuring as Master"
    
fi



