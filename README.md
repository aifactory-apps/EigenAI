## EigenAI

This repository is AiFactory redistribution of Eigen - popular C++ library for fast linear algebra calculation. 
Version of original library: `3.3.4`

Initial source could be found here: https://bitbucket.org/eigen/eigen/

The main reason of our redistribution - wrap original Eigen in separate `Eigen_ai` namespace to avoid possible link deduplication issues in case when our library is used within other one with the similar Eigen library dependency (but other version)

Contact rutsh@aifactory.app or savchenkov@aifactory.app if you have any questions. For more information go to http://eigen.tuxfamily.org/.
