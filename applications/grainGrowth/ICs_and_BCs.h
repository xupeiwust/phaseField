template <int dim>
double InitialCondition<dim>::value (const dealii::Point<dim> &p, const unsigned int component) const
{
  double scalar_IC;
	  // =====================================================================
	  // ENTER THE INITIAL CONDITIONS HERE FOR SCALAR FIELDS
	  // =====================================================================
	  // Enter the function describing conditions for the fields at point "p".
	  // Use "if" statements to set the initial condition for each variable
	  // according to its variable index.

	  // The initial condition is a set of overlapping circles/spheres defined
	  // by a hyperbolic tangent function. The center of each circle/sphere is
	  // given by "center" and its radius is given by "radius".

	  double center[10][3] = {{0.3,0.3,0},{0.7,0.7,0},{0.5,0.1,0},{0.4,0.5,0},{0.3,0.9,0},{0.1,0.1,0},{0.1,0.7,0},{0.6,0.6,0},{0.7,0.4,0},{0.7,0.2,0}};
	  double rad[12] = {6, 7, 9, 8, 5, 6, 4, 3, 8, 5};
	  double domain_size[3] = {spanX,spanY,spanZ};
	  double dist = 0.0;
	  scalar_IC = 0;

	  for (unsigned int dir = 0; dir < dim; dir++){
		  dist += (p[dir]-center[index][dir]*domain_size[dir])*(p[dir]-center[index][dir]*domain_size[dir]);
	  }
	  dist = std::sqrt(dist);

	  scalar_IC +=	0.5*(1.0-std::tanh((dist-rad[index])/0.8));

	  // =====================================================================
	  return scalar_IC;
}

template <int dim>
void InitialConditionVec<dim>::vector_value (const dealii::Point<dim> &p, dealii::Vector<double> &vector_IC) const
{
	  // =====================================================================
	  // ENTER THE INITIAL CONDITIONS HERE FOR VECTOR FIELDS
	  // =====================================================================
	  // Enter the function describing conditions for the fields at point "p".
	  // Use "if" statements to set the initial condition for each variable
	  // according to its variable index.


	  // =====================================================================
}

template <int dim, int degree>
void customPDE<dim,degree>::setBCs(){
	// =====================================================================
	// ENTER THE BOUNDARY CONDITIONS HERE
	// =====================================================================
	// This function sets the BCs for the problem variables
	// The function "inputBCs" should be called for each component of
	// each variable and should be in numerical order. Four input arguments
	// set the same BC on the entire boundary. Two plus two times the
	// number of dimensions inputs sets separate BCs on each face of the domain.
	//
	// Inputs to "inputBCs":
	// First input: variable number
	// Second input: component number
	// Third input: BC type (options are "ZERO_DERIVATIVE", "DIRICHLET", and "PERIODIC")
	// Fourth input: BC value (ignored unless the BC type is "DIRICHLET")
	// Odd inputs after the third: BC type
	// Even inputs after the third: BC value
	// Face numbering: starts at zero with the minimum of the first direction, one for the maximum of the first direction
	//						two for the minimum of the second direction, etc. (i.e. left-right-bottom-top in 2D).
	//
	// Example 1: Periodic BC for all boundaries for variable 2, component 2:
	// this->inputBCs(2,2,"PERIODIC",0);
	//
	// Example 2: Dirichlet BCs with a value of 1.0 on the top and bottom boundaries, zero-derivative on the left and right
	// for variable 0, component 0:
	// this->inputBCs(0,0,"DIRICHLET",1.0,"DIRICHLET",1.0,"ZERO_DERIVATIVE",0,"ZERO_DERIVATIVE",0);

	this->inputBCs(0,0,"PERIODIC",0);
	this->inputBCs(1,0,"PERIODIC",0);
	this->inputBCs(2,0,"PERIODIC",0);
	this->inputBCs(3,0,"PERIODIC",0);
	this->inputBCs(4,0,"PERIODIC",0);
	this->inputBCs(5,0,"PERIODIC",0);
	this->inputBCs(6,0,"PERIODIC",0);
	this->inputBCs(7,0,"PERIODIC",0);
	this->inputBCs(8,0,"PERIODIC",0);
	this->inputBCs(9,0,"PERIODIC",0);

	// =====================================================================

}

