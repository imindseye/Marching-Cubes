////////////////////////////////////////////////////////////
//
//  Marching Cubes  IsoSurface Class
//
//  Han-Wei Shen   hwshen@nas.nasa.gov
//
////////////////////////////////////////////////////////////

#ifndef VT_ISOSURFACE_H 
#define VT_ISOSURFACE_H 1 

class vtIsoSurf {

protected: 
  
  float *isov; 
  int nisov; 
  int nisov_allocated; 

  float* field; 
  int xdim, ydim, zdim; 

  void iso_cell(float v); 
  
public:

  vtIsoSurf(float* field, int dx, int dy, int dz); 
  ~vtIsoSurf(); 

  void set_isov(float v); 
  void set_isov(float*, int); 

  virtual void execute(); 

}; 

#endif










