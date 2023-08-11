Circle
======

Casey's solution can be found [here](https://www.computerenhance.com/p/efficient-dda-circle-outlines). I didn't actually watch the video, but he seems to think it's pretty fast! The code certainly _looks_ fast...

My solution is undoubtedly several times slower, but it was fun to write! (It's also much more easily understood and doesn't throw warnings for undefined behavior.)

I spent no time researching circle drawing -- this was an attempt from scratch that I tweaked until it looked good enough. Try drawing a circle of radius 1 or 2! So cute!

Building
--------
Casey's version:
```
cd casey
make
```

My version:
```
cd me
make
```
`make`

Running
-------
Casey's version: (doesn't take command line arguments)
```
cd casey
make run
```

My version:
```
cd me
make run ARGS=<radius>
```

Examples
--------
Following are some expected outputs when running my version. They tend to look a little more even (less vertically stretched) in the terminal.

`make run ARGS=4`
```
     # # #      
   #       #    
 #           #  
 #           #  
 #           #  
   #       #    
     # # #      
```

`make run ARGS=16`
```
                         # # # # # # #                          
                   # # #               # # #                    
               # #                           # #                
             #                                   #              
           #                                       #            
         #                                           #          
       #                                               #        
     #                                                   #      
     #                                                   #      
   #                                                       #    
   #                                                       #    
   #                                                       #    
 #                                                           #  
 #                                                           #  
 #                                                           #  
 #                                                           #  
 #                                                           #  
 #                                                           #  
 #                                                           #  
   #                                                       #    
   #                                                       #    
   #                                                       #    
     #                                                   #      
     #                                                   #      
       #                                               #        
         #                                           #          
           #                                       #            
             #                                   #              
               # #                           # #                
                   # # #               # # #                    
                         # # # # # # #                          
```

p.s.
----
Isn't it hilarious that 50% of the project is Makefile? That's C and C++ for ya ;)
