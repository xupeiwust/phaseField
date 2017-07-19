template <int dim>
double InitialCondition<dim>::value (const Point<dim> &p, const unsigned int component) const
{
	  double scalar_IC = 0;
	  // =====================================================================
	  // ENTER THE INITIAL CONDITIONS HERE FOR SCALAR FIELDS
	  // =====================================================================
	  // Enter the function describing conditions for the fields at point "p".
	  // Use "if" statements to set the initial condition for each variable
	  // according to its variable index.

	  double r=0.0;

	  if (index == 0){
			r = 0.0;
			for (unsigned int dir = 0; dir < dim; dir++){
				r += (p[dir]-userInputs.domain_size[dir]/2.0)*(p[dir]-userInputs.domain_size[dir]/2.0);
			}
			r = std::sqrt(r);
			double n = 0.5*(1.0-std::tanh((r-userInputs.domain_size[0]/4.0)/4.0));
			scalar_IC = 0.082*16.0/(userInputs.domain_size[0]/4.0)+(3.0*n*n-2.0*n*n*n);

	  }
	  else if (index == 1) {
			r = 0.0;
			for (unsigned int dir = 0; dir < dim; dir++){
			  r += (p[dir]-userInputs.domain_size[dir]/2.0)*(p[dir]-userInputs.domain_size[dir]/2.0);
			}
			r = std::sqrt(r);
            scalar_IC = 0.5*(1.0-std::tanh((r-userInputs.domain_size[0]/4.0)/4.0));
	  }
	  else {
		  scalar_IC = 0.0;
	  }

	  // =====================================================================
	  return scalar_IC;
}

template <int dim>
void InitialConditionVec<dim>::vector_value (const Point<dim> &p,Vector<double> &vector_IC) const
{
	  // =====================================================================
	  // ENTER THE INITIAL CONDITIONS HERE FOR VECTOR FIELDS
	  // =====================================================================
	  // Enter the function describing conditions for the fields at point "p".
	  // Use "if" statements to set the initial condition for each variable
	  // according to its variable index.


	  // =====================================================================
}
