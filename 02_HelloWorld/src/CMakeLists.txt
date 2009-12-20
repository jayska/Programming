
ADD_LIBRARY( shapes shape rectangle line point )

# Generate libobject.a
ADD_LIBRARY( object object types value )

TARGET_LINK_LIBRARIES( object shapes )