
#ifndef __Analysis_H__
#define __Analysis_H__



 #include <iostream>
 #include <sstream>
 #include <stdio.h>
 #include <ml.h>
 #include "Ampl.h"



 #include "opencv2/core/core.hpp"
 #include "opencv2/core/opengl_interop.hpp"
 #include "opencv2/highgui/highgui.hpp"
 #include "opencv2/imgproc/imgproc.hpp"
 #include "opencv2/calib3d/calib3d.hpp"
 #include "opencv2/contrib/contrib.hpp"


#include </home/fabiano/dlib-18.14/dlib/bayes_utils.h>
#include </home/fabiano/dlib-18.14/dlib/graph_utils.h>
#include </home/fabiano/dlib-18.14/dlib/graph.h>
#include </home/fabiano/dlib-18.14/dlib/directed_graph.h>
#include <iostream>



using namespace std;
using namespace cv;
using namespace dlib;




float  Analysis(Pernas &Sl,Bracos &Sa,Cabecas &Sh)
{

try
    {
        // There are many useful convenience functions in this namespace.  They all
        // perform simple access or modify operations on the nodes of a bayesian network.
        // You don't have to use them but they are convenient and they also will check for
        // various errors in your bayesian network when your application is built with
        // the DEBUG or ENABLE_ASSERTS preprocessor definitions defined.  So their use
        // is recommended.  In fact, most of the global functions used in this example
        // program are from this namespace.
        using namespace bayes_node_utils;

        // This statement declares a bayesian network called bn.  Note that a bayesian network
        // in the dlib world is just a directed_graph object that contains a special kind
        // of node called a bayes_node.
        directed_graph<bayes_node>::kernel_1a_c bn;

        // Use an enum to make some more readable names for our nodes.
        enum nodes
        {
            SH1 = 0,
            SH2 = 1,
            SH3 = 2,
            SA1 = 3,
            SA2 = 4,
            SA3 = 5,
            SL1 = 6,
            SL2 = 7,
            SL3 = 8,
            H   = 9,
            A   = 10,
            L   = 11,
            HB  = 12

        };

        // The next few blocks of code setup our bayesian network.

        // The first thing we do is tell the bn object how many nodes it has
        // and also add the three edges.  Again, we are using the network
        // shown in ASCII art at the top of this file.
        bn.set_number_of_nodes(13);
        bn.add_edge(H, HB);
        bn.add_edge(SH1, H);
        bn.add_edge(SH2, H);
        bn.add_edge(SH3, H);
        bn.add_edge(A, HB);
        bn.add_edge(SA1, A);
        bn.add_edge(SA2, A);
        bn.add_edge(SA3, A);
        bn.add_edge(L,HB);
        bn.add_edge(SL1,L);
        bn.add_edge(SL2,L);
        bn.add_edge(SL3,L);




        // Now we inform all the nodes in the network that they are binary
        // nodes.  That is, they only have two possible values.
        set_node_num_values(bn, SH1, 2);
        set_node_num_values(bn, SH2, 2);
        set_node_num_values(bn, SH3, 2);
        set_node_num_values(bn, SA1, 2);
        set_node_num_values(bn, SA2, 2);
        set_node_num_values(bn, SA3, 2);
        set_node_num_values(bn, SL1, 2);
        set_node_num_values(bn, SL2, 2);
        set_node_num_values(bn, SL3, 2);
        set_node_num_values(bn, H, 2);
        set_node_num_values(bn, A, 2);
        set_node_num_values(bn, L, 2);
        set_node_num_values(bn, HB, 2);


        assignment parent_state;
        // Now we will enter all the conditional probability information for each node.
        // Each node's conditional probability is dependent on the state of its parents.
        // To specify this state we need to use the assignment object.  This assignment
        // object allows us to specify the state of each nodes parents.


        // Here we specify that p(B=1) = 0.01
        // parent_state is empty in this case since B is a root node.
        set_node_probability(bn, SH1, 1, parent_state, 0.9425);
        // Here we specify that p(B=0) = 1-0.01
        set_node_probability(bn, SH1, 0, parent_state, 1-0.9425);


        // Here we specify that p(C=1) = 0.001
        // parent_state is empty in this case since B is a root node.
        set_node_probability(bn, SH2, 1, parent_state, 0.9719);
        // Here we specify that p(C=0) = 1-0.001
        set_node_probability(bn, SH2, 0, parent_state, 1-0.9719);


        // Here we specify that p(C=1) = 0.001
        // parent_state is empty in this case since B is a root node.
        set_node_probability(bn, SH3, 1, parent_state, 0.9048);
        // Here we specify that p(C=0) = 1-0.001
        set_node_probability(bn, SH3, 0, parent_state, 1-0.9048);


        // Here we specify that p(C=1) = 0.001
        // parent_state is empty in this case since B is a root node.
        set_node_probability(bn, SA1, 1, parent_state, 0.8833);
        // Here we specify that p(C=0) = 1-0.001
        set_node_probability(bn, SA1, 0, parent_state, 1-0.8833);


        // Here we specify that p(C=1) = 0.001
        // parent_state is empty in this case since B is a root node.
        set_node_probability(bn, SA2, 1, parent_state, 0.8794);
        // Here we specify that p(C=0) = 1-0.001
        set_node_probability(bn, SA2, 0, parent_state, 1-0.8794);


        // Here we specify that p(C=1) = 0.001
        // parent_state is empty in this case since B is a root node.
        set_node_probability(bn, SA3, 1, parent_state, 0.8471);
        // Here we specify that p(C=0) = 1-0.001
        set_node_probability(bn, SA3, 0, parent_state, 1-0.8471);


        // Here we specify that p(C=1) = 0.001
        // parent_state is empty in this case since B is a root node.
        set_node_probability(bn, SL1, 1, parent_state, 0.8594);
        // Here we specify that p(C=0) = 1-0.001
        set_node_probability(bn, SL1, 0, parent_state, 1-0.8594);


        // Here we specify that p(C=1) = 0.001
        // parent_state is empty in this case since B is a root node.
        set_node_probability(bn, SL2, 1, parent_state, 0.9027);
        // Here we specify that p(C=0) = 1-0.001
        set_node_probability(bn, SL2, 0, parent_state, 1-0.9027);


        // Here we specify that p(C=1) = 0.001
        // parent_state is empty in this case since B is a root node.
        set_node_probability(bn, SL3, 1, parent_state, 0.8265);
        // Here we specify that p(C=0) = 1-0.001
        set_node_probability(bn, SL3, 0, parent_state, 1-0.8265);




//PROBABILIDADES PARA A EXISTÊNCIA DE UMA CABEÇA.
        // This is our first node that has parents. So we set the parent_state
        // object to reflect that A has both B and C as parents.
        parent_state.add(SH1, 1);
        parent_state.add(SH2, 1);
        parent_state.add(SH3, 1);
        // Here we specify that p(A=1 | B=1, C=1) = 0.99
        set_node_probability(bn, H, 1, parent_state, 1);
        // Here we specify that p(A=0 | B=1, C=1) = 1-0.99
        set_node_probability(bn, H, 0, parent_state, 1-1);


        // Here we use the [] notation because B and C have already
        // been added into parent state.
        parent_state[SH1] = 1;
        parent_state[SH2] = 0;
        parent_state[SH3] = 0;
        // Here we specify that p(A=1 | B=1, C=0) = 0.9
        set_node_probability(bn, H, 1, parent_state, 0.9998);
        set_node_probability(bn, H, 0, parent_state, 1-0.99998);



        parent_state[SH1] = 0;
        parent_state[SH2] = 1;
        parent_state[SH3] = 0;
        // Here we specify that p(A=1 | B=0, C=1) = 0.5
        set_node_probability(bn, H, 1, parent_state, 0.9978);
        set_node_probability(bn, H, 0, parent_state, 1-0.9978);



        parent_state[SH1] = 1;
        parent_state[SH2] = 1;
        parent_state[SH3] = 0;
        // Here we specify that p(A=1 | B=0, C=0) = 0.01
        set_node_probability(bn, H, 1, parent_state, 1);
        set_node_probability(bn, H, 0, parent_state, 1-1);


        parent_state[SH1] = 0;
        parent_state[SH2] = 0;
        parent_state[SH3] = 1;
        // Here we specify that p(A=1 | B=0, C=0) = 0.01
        set_node_probability(bn, H, 1, parent_state, 0.9976);
        set_node_probability(bn, H, 0, parent_state, 1-0.9976);


        parent_state[SH1] = 1;
        parent_state[SH2] = 0;
        parent_state[SH3] = 1;
        // Here we specify that p(A=1 | B=0, C=0) = 0.01
        set_node_probability(bn, H, 1, parent_state, 1);
        set_node_probability(bn, H, 0, parent_state, 1-1);


        parent_state[SH1] = 0;
        parent_state[SH2] = 1;
        parent_state[SH3] = 1;
        // Here we specify that p(A=1 | B=0, C=0) = 0.01
        set_node_probability(bn, H, 1, parent_state, 0.9999);
        set_node_probability(bn, H, 0, parent_state, 1-0.9999);


        parent_state[SH1] = 0;
        parent_state[SH2] = 0;
        parent_state[SH3] = 0;
        // Here we specify that p(A=1 | B=0, C=0) = 0.01
        set_node_probability(bn, H, 1, parent_state, 0.0);
        set_node_probability(bn, H, 0, parent_state, 1-0.0);




//PROBABILIDADES PARA A EXISTÊNCIA DE UM BRAÇO.
        // This is our first node that has parents. So we set the parent_state
        // object to reflect that A has both B and C as parents.
        parent_state.clear();
        parent_state.add(SA1, 1);
        parent_state.add(SA2, 1);
        parent_state.add(SA3, 1);
        // Here we specify that p(A=1 | B=1, C=1) = 0.99
        set_node_probability(bn, A, 1, parent_state, 0.9978);
        // Here we specify that p(A=0 | B=1, C=1) = 1-0.99
        set_node_probability(bn, A, 0, parent_state, 1-0.9978);


        // Here we use the [] notation because B and C have already
        // been added into parent state.
        parent_state[SA1] = 1;
        parent_state[SA2] = 0;
        parent_state[SA3] = 0;
        // Here we specify that p(A=1 | B=1, C=0) = 0.9
        set_node_probability(bn, A, 1, parent_state, 0.8833);
        set_node_probability(bn, A, 0, parent_state, 1-0.8833);



        parent_state[SA1] = 0;
        parent_state[SA2] = 1;
        parent_state[SA3] = 0;
        // Here we specify that p(A=1 | B=0, C=1) = 0.5
        set_node_probability(bn, A, 1, parent_state, 0.8795);
        set_node_probability(bn, A, 0, parent_state, 1-0.8795);



        parent_state[SA1] = 1;
        parent_state[SA2] = 1;
        parent_state[SA3] = 0;
        // Here we specify that p(A=1 | B=0, C=0) = 0.01
        set_node_probability(bn, A, 1, parent_state, 0.9859);
        set_node_probability(bn, A, 0, parent_state, 1-0.9859);


        parent_state[SA1] = 0;
        parent_state[SA2] = 0;
        parent_state[SA3] = 1;
        // Here we specify that p(A=1 | B=0, C=0) = 0.01
        set_node_probability(bn, A, 1, parent_state, 0.8471);
        set_node_probability(bn, A, 0, parent_state, 1-0.8471);


        parent_state[SA1] = 1;
        parent_state[SA2] = 0;
        parent_state[SA3] = 1;
        // Here we specify that p(A=1 | B=0, C=0) = 0.01
        set_node_probability(bn, A, 1, parent_state, 0.9821);
        set_node_probability(bn, A, 0, parent_state, 1-0.9821);


        parent_state[SA1] = 0;
        parent_state[SA2] = 1;
        parent_state[SA3] = 1;
        // Here we specify that p(A=1 | B=0, C=0) = 0.01
        set_node_probability(bn, A, 1, parent_state, 0.9815);
        set_node_probability(bn, A, 0, parent_state, 1-0.9815);


        parent_state[SA1] = 0;
        parent_state[SA2] = 0;
        parent_state[SA3] = 0;
        // Here we specify that p(A=1 | B=0, C=0) = 0.01
        set_node_probability(bn, A, 1, parent_state, 0.0);
        set_node_probability(bn, A, 0, parent_state, 1-0.0);




        //PROBABILIDADES PARA A EXISTÊNCIA DE UMA PERNA.
        // This is our first node that has parents. So we set the parent_state
        // object to reflect that A has both B and C as parents.
        parent_state.clear();
        parent_state.add(SL1, 1);
        parent_state.add(SL2, 1);
        parent_state.add(SL3, 1);
        // Here we specify that p(A=1 | B=1, C=1) = 0.99
        set_node_probability(bn, L, 1, parent_state, 0.9976);
        // Here we specify that p(A=0 | B=1, C=1) = 1-0.99
        set_node_probability(bn, L, 0, parent_state, 1-0.9976);


        // Here we use the [] notation because B and C have already
        // been added into parent state.
        parent_state[SL1] = 1;
        parent_state[SL2] = 0;
        parent_state[SL3] = 0;
        // Here we specify that p(A=1 | B=1, C=0) = 0.9
        set_node_probability(bn, L, 1, parent_state, 0.8594);
        set_node_probability(bn, L, 0, parent_state, 1-0.8594);



        parent_state[SL1] = 0;
        parent_state[SL2] = 1;
        parent_state[SL3] = 0;
        // Here we specify that p(A=1 | B=0, C=1) = 0.5
        set_node_probability(bn, L, 1, parent_state, 0.9027);
        set_node_probability(bn, L, 0, parent_state, 1-0.9027);



        parent_state[SL1] = 1;
        parent_state[SL2] = 1;
        parent_state[SL3] = 0;
        // Here we specify that p(A=1 | B=0, C=0) = 0.01
        set_node_probability(bn, L, 1, parent_state, 0.9863);
        set_node_probability(bn, L, 0, parent_state, 1-0.9863);


        parent_state[SL1] = 0;
        parent_state[SL2] = 0;
        parent_state[SL3] = 1;
        // Here we specify that p(A=1 | B=0, C=0) = 0.01
        set_node_probability(bn, L, 1, parent_state, 0.8265);
        set_node_probability(bn, L, 0, parent_state, 1-0.8265);


        parent_state[SL1] = 1;
        parent_state[SL2] = 0;
        parent_state[SL3] = 1;
        // Here we specify that p(A=1 | B=0, C=0) = 0.01
        set_node_probability(bn, L, 1, parent_state, 0.9756);
        set_node_probability(bn, L, 0, parent_state, 1-0.9756);


        parent_state[SL1] = 0;
        parent_state[SL2] = 1;
        parent_state[SL3] = 1;
        // Here we specify that p(A=1 | B=0, C=0) = 0.01
        set_node_probability(bn, L, 1, parent_state, 0.9831);
        set_node_probability(bn, L, 0, parent_state, 1-0.9831);


        parent_state[SL1] = 0;
        parent_state[SL2] = 0;
        parent_state[SL3] = 0;
        // Here we specify that p(A=1 | B=0, C=0) = 0.01
        set_node_probability(bn, L, 1, parent_state, 0.0);
        set_node_probability(bn, L, 0, parent_state, 1-0.0);





//PROBABILIDADE DE HB DADO QUE HÁ H,A E L.
        // Here we set probabilities for node D.
        // First we clear out parent state so that it doesn't have any of
        // the assignments for the B and C nodes used above.
        parent_state.clear();
        parent_state.add(H,1);
        parent_state.add(A,1);
        parent_state.add(L,1);
        //parent_state.add(P, 1);
        //parent_state.add(P, 1);
        // Here we specify that p(D=1 | A=1) = 0.5
        set_node_probability(bn, HB, 1, parent_state, 0.9975);
        set_node_probability(bn, HB, 0, parent_state, 1-0.9975);

        parent_state[H] = 1;
        parent_state[A] = 0;
        parent_state[L] = 0;
        // Here we specify that p(D=1 | A=0) = 0.2
        set_node_probability(bn, HB, 1, parent_state, 0.9048);
        set_node_probability(bn, HB, 0, parent_state, 1-0.9048);

        parent_state[H] = 0;
        parent_state[A] = 1;
        parent_state[L] = 0;
        // Here we specify that p(D=1 | A=0) = 0.2
        set_node_probability(bn, HB, 1, parent_state, 0.8471);
        set_node_probability(bn, HB, 0, parent_state, 1-0.8471);

        parent_state[H] = 1;
        parent_state[A] = 1;
        parent_state[L] = 0;
        // Here we specify that p(D=1 | A=0) = 0.2
        set_node_probability(bn, HB, 1, parent_state, 0.9854);
        set_node_probability(bn, HB, 0, parent_state, 1-0.9854);

        parent_state[H] = 0;
        parent_state[A] = 0;
        parent_state[L] = 1;
        // Here we specify that p(D=1 | A=0) = 0.2
        set_node_probability(bn, HB, 1, parent_state, 0.8265);
        set_node_probability(bn, HB, 0, parent_state, 1-0.8265);

        parent_state[H] = 1;
        parent_state[A] = 0;
        parent_state[L] = 1;
        // Here we specify that p(D=1 | A=0) = 0.2
        set_node_probability(bn, HB, 1, parent_state, 0.9835);
        set_node_probability(bn, HB, 0, parent_state, 1-0.9835);

        parent_state[H] = 0;
        parent_state[A] = 1;
        parent_state[L] = 1;
        // Here we specify that p(D=1 | A=0) = 0.2
        set_node_probability(bn, HB, 1, parent_state, 0.9735);
        set_node_probability(bn, HB, 0, parent_state, 1-0.9735);

        parent_state[H] = 0;
        parent_state[A] = 0;
        parent_state[L] = 0;
        // Here we specify that p(D=1 | A=0) = 0.2
        set_node_probability(bn, HB, 1, parent_state, 0.0);
        set_node_probability(bn, HB, 0, parent_state, 1-0.0);








        // We have now finished setting up our bayesian network.  So let's compute some
        // probability values.  The first thing we will do is compute the prior probability
        // of each node in the network.  To do this we will use the join tree algorithm which
        // is an algorithm for performing exact inference in a bayesian network.

        // First we need to create an undirected graph which contains set objects at each node and
        // edge.  This long declaration does the trick.
        typedef dlib::set<unsigned long>::compare_1b_c set_type;
        typedef graph<set_type, set_type>::kernel_1a_c join_tree_type;
        join_tree_type join_tree;

        // Now we need to populate the join_tree with data from our bayesian network.  The next
        // function calls do this.  Explaining exactly what they do is outside the scope of this
        // example.  Just think of them as filling join_tree with information that is useful
        // later on for dealing with our bayesian network.
        create_moral_graph(bn, join_tree);
        create_join_tree(join_tree, join_tree);

        // Now that we have a proper join_tree we can use it to obtain a solution to our
        // bayesian network.  Doing this is as simple as declaring an instance of
        // the bayesian_network_join_tree object as follows:
        bayesian_network_join_tree solution(bn, join_tree);


        // now print out the probabilities for each node
        //cout << "Using the join tree algorithm:\n";
        //cout << "p(SH1=1) = " << solution.probability(SH1)(1) << endl;
        //cout << "p(SH1=0) = " << solution.probability(SH1)(0) << endl;
        //cout << "p(SH2=1) = " << solution.probability(SH2)(1) << endl;
        //cout << "p(SH2=0) = " << solution.probability(SH2)(0) << endl;
        //cout << "p(SH3=1) = " << solution.probability(SH3)(1) << endl;
        //cout << "p(SH3=0) = " << solution.probability(SH3)(0) << endl;
        //cout << "p(SA1=1) = " << solution.probability(SA1)(1) << endl;
        //cout << "p(SA1=0) = " << solution.probability(SA1)(0) << endl;
        //cout << "p(SA2=1) = " << solution.probability(SA2)(1) << endl;
        //cout << "p(SA2=0) = " << solution.probability(SA2)(0) << endl;
        //cout << "p(SA3=1) = " << solution.probability(SA3)(1) << endl;
        //cout << "p(SA3=0) = " << solution.probability(SA3)(0) << endl;
        //cout << "p(SL1=1) = " << solution.probability(SL1)(1) << endl;
        //cout << "p(SL1=0) = " << solution.probability(SL1)(0) << endl;
        //cout << "p(SL2=1) = " << solution.probability(SL2)(1) << endl;
        //cout << "p(SL2=0) = " << solution.probability(SL2)(0) << endl;
        //cout << "p(SL3=1) = " << solution.probability(SL3)(1) << endl;
        //cout << "p(SL3=0) = " << solution.probability(SL3)(0) << endl;
        //cout << "p(H=1) = " << solution.probability(H)(1) << endl;
        //cout << "p(H=0) = " << solution.probability(H)(0) << endl;
        //cout << "p(A=1) = " << solution.probability(A)(1) << endl;
        //cout << "p(A=0) = " << solution.probability(A)(0) << endl;
        //cout << "p(L=1) = " << solution.probability(L)(1) << endl;
        //cout << "p(L=0) = " << solution.probability(L)(0) << endl;
        //cout << "p(HB=1) = " << solution.probability(HB)(1) << endl;
        //cout << "p(HB=0) = " << solution.probability(HB)(0) << endl;





        cout << "\n\n\n";


        // Now to make things more interesting let's say that we have discovered that the C
        // node really has a value of 1.  That is to say, we now have evidence that
        // C is 1.  We can represent this in the network using the following two function
        // calls.



        set_node_value(bn, SH1, Sh.SH1);
        set_node_as_evidence(bn, SH1);

        set_node_value(bn, SH2, Sh.SH2);
        set_node_as_evidence(bn, SH2);

        set_node_value(bn, SH3, Sh.SH3);
        set_node_as_evidence(bn, SH3);




        set_node_value(bn, SA1, Sa.SA1);
        set_node_as_evidence(bn, SA1);

        set_node_value(bn, SA2, Sa.SA2);
        set_node_as_evidence(bn, SA2);

        set_node_value(bn, SA3, Sa.SA3);
        set_node_as_evidence(bn, SA3);



        set_node_value(bn, SL1, Sl.SL1);
        set_node_as_evidence(bn, SL1);

        set_node_value(bn, SL2, Sl.SL2);
        set_node_as_evidence(bn, SL2);

        set_node_value(bn, SL3, Sl.SL3);
        set_node_as_evidence(bn, SL3);




        // Now we want to compute the probabilities of all the nodes in the network again
        // given that we now know that C is 1.  We can do this as follows:
        bayesian_network_join_tree solution_with_evidence(bn, join_tree);

        // now print out the probabilities for each node
        //cout << "Using the join tree algorithm:\n";
        //cout << "p(HB=1 | H, A , L ) = " << solution_with_evidence.probability(HB)(1) << endl;
        //cout << "p(HB=0 | H, A , L ) = " << solution_with_evidence.probability(HB)(0) << endl;

        //cout << "\n\n\n";

        return (solution_with_evidence.probability(HB)(1));

    }
    catch (std::exception& e)
    {
        cout << "exception thrown: " << endl;
        cout << e.what() << endl;
        cout << "hit enter to terminate" << endl;
        cin.get();
    }




}



#endif //__Analysis_H__
