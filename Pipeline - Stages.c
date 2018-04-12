import com.cloudbees.groovy.cps.NonCPS


node('EDA-LA-01-edalab')
{
      stage('Build - Sync')
      {
	        try
          {
            timeout(time: 30, unit: 'DAYS')
            {
              p4sync charset: 'none', credential: 'd1b38a63-ab5c-4bd0-a600-0886e0180394', populate: syncOnly(force: false, have: true, modtime: false, parallel: [enable: false, minbytes: '1024', minfiles: '1', threads: '4'], pin: '', quiet: true, revert: false), source: templateSource('wt-QuickLog')
            }
            currentBuild.result = 'SUCCESS'
          }
          catch (err)
          {
            currentBuild.result = 'FAILED'
            throw (err)
          }
          finally
          {
            echo 'build sync finished'
          }
	      }

        stage('Build - Devjob')
	      {
	         try
           {
             timeout(time: 30, unit: 'DAYS')
             {
             }
             currentBuild.result = 'SUCCESS'
           }
         catch (err)
         {
            currentBuild.result = 'FAILED'
            throw (err)
          }
          finally
          {
            echo 'Devjob Execution finished'
          }
	      }

         stage('Build - Deploy')
	       {
	          try
            {
              timeout(time: 30, unit: 'DAYS')
              {
              }
            currentBuild.result = 'SUCCESS'
            }
            catch (err)
            {
            currentBuild.result = 'FAILED'
            throw (err)
            }
            finally
            {
              echo 'Deploy to Build DM41 finished'
            }
	         }


           stage('Build - Master XML')
	         {
	            try
              {
                timeout(time: 30, unit: 'DAYS')
                {
                }
                currentBuild.result = 'SUCCESS'
              }
              catch (err)
              {
                currentBuild.result = 'FAILED'
                throw (err)
              }
              finally
              {
                echo 'Master xml file creation completed'
              }
	          }


	         stage('Test - Static')
	         {
          	  try
              {
                timeout(time: 30, unit: 'DAYS')
                {
                }
                currentBuild.result = 'SUCCESS'
              }
              catch (err)
              {
                currentBuild.result = 'FAILED'
                throw (err)
              }
              finally
              {
                echo 'VIA Test Execution finished'
              }
	          }


            stage('Test - Dynamic Test')
	          {
          	  try
              {
                timeout(time: 30, unit: 'DAYS')
                {
                }
                currentBuild.result = 'SUCCESS'
              }
              catch (err)
              {
                currentBuild.result = 'FAILED'
                throw (err)
              }
              finally
              {
                echo 'UTF based dynamic test execution finished'
              }
        	  }


            stage('Release - DM44 job')
	          {
          	  try
              {
                timeout(time: 30, unit: 'DAYS')
                {
                }
                currentBuild.result = 'SUCCESS'
              }
              catch (err)
              {
                currentBuild.result = 'FAILED'
                throw (err)
              }
              finally
              {
                echo 'DM44 Release job finished'
              }
          	}


            stage('Release - Deploy DM44')
          	{
          	  try
              {
                timeout(time: 30, unit: 'DAYS')
                {
                }
                currentBuild.result = 'SUCCESS'
              }
              catch (err)
              {
                currentBuild.result = 'FAILED'
                throw (err)
              }
              finally
              {
                echo 'Deployment to DM44 is finished...'
              }
          	}


          	stage('Release - Master XML')
          	{
          	  try
              {
                timeout(time: 30, unit: 'DAYS')
                {
                }
                currentBuild.result = 'SUCCESS'
              }
              catch (err)
              {
                currentBuild.result = 'FAILED'
                throw (err)
              }
              finally
              {
                echo 'Generate master xml in DM44 is finished..'
              }
          	}


            stage('DM44 Test')
          	{
          	  try
              {
                timeout(time: 30, unit: 'DAYS')
                {
                }
                currentBuild.result = 'SUCCESS'
              }
              catch (err)
              {
                currentBuild.result = 'FAILED'
                throw (err)
              }
              finally
              {
                echo 'Unit test in DM44 package is finished.'
              }
          	}


          	stage('Stage to Production')
          	{
          	  try
              {
                timeout(time: 30, unit: 'DAYS')
                {
                }
                currentBuild.result = 'SUCCESS'
              }
              catch (err)
              {
                currentBuild.result = 'FAILED'
                throw (err)
              }
              finally
              {
                echo 'Replication to Production server is completed....'
              }
          	}
            }





            node('EDA-LA-01-edalab')
            {
              stage('Setup2')
            	{
            	  try
                {
                  timeout(time: 30, unit: 'DAYS')
                  {
                  }
                  currentBuild.result = 'SUCCESS'
                }
                catch (err)
                {
                  currentBuild.result = 'FAILED'
                  throw (err)
                }
                finally
                {
                  echo 'build finished'
                }
            	}
            }
