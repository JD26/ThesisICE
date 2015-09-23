rm(list = ls())

FaddeevLeverrier <- function(A){ 
  # Calculate the coeficients of
  # characteristic poly of A
  # Algorithm :
  # Faddeev-Leverrier
  n = dim(A)[1]
  C = A
  c = rep(0,n)
  for ( i in 1:(n-1) ){
    c[i]= -sum(diag(C))/i
    C = A%*%( C + diag( rep(c[i],n) ) )    
  }
  c[n]= -sum(diag(C))/n  
  c = c(1,c)
  return(c)
}
