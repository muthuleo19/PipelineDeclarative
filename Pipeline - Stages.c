import com.cloudbees.groovy.cps.NonCPS

environment
  {
		Workspace-Path = "C:\\Jenkins\\workspace"
  }

node('EDA-LA-01-edalab')
{
      stage('Build - Sync Workspace')
      {
	        try
          {
            timeout(time: 30, unit: 'DAYS')
            {
              p4sync charset: 'none', credential: 'd1b38a63-ab5c-4bd0-a600-0886e0180394', populate: syncOnly(force: false, have: true, modtime: false, parallel: [enable: false, minbytes: '1024', minfiles: '1', threads: '4'], pin: '', quiet: true, revert: false), source: templateSource('${Workspace}')
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
            echo 'Workspace sync for the build is successful'
          }
	      }

        stage('Build - Devjob Execution')
	      {
	         try
           {
             timeout(time: 30, unit: 'DAYS')
             {
               bat 'C:\\Batch\\build2\\labview-cli --kill --lv-ver 2014 "C:\\Batch\\build2\\Build VIPB Spec.vi" -- "%Workspace-Path%\\QuickLog\\.vipb" %DEV% %BUILD_NUMBER% "False" "Packages\\LabAutomation\\Teststand\\Custom Steps\\Datalogging" "Configuration_Files\\LabAutomation\\Teststand\\Datalogging" "TestStand" "NA" " "'
				       archiveArtifacts '*.vip,QuickLog/QuickLog.html'
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

         stage('Build - Deployment to DM41')
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
              echo 'Deployment of build package to DM41 server is successful'
            }
	         }


           stage('Build - Master XML - DM41')
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
                echo 'Master xml file creation in DM41 is completed'
              }
	          }


	         stage('DM41 Test - VIA')
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
                echo 'VIA Test Execution in DM41 is finished'
              }
	          }


            stage('DM41 Test - UTF')
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
                echo 'UTF based dynamic test execution in DM41 is finished'
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


            stage('Release - Deployment to DM44')
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
                echo 'Deployment of Package to DM44 is finished...'
              }
          	}


          	stage('Release - Master XML - DM44')
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
                echo 'Master xml generation in DM44 is finished..'
              }
          	}


            stage('DM44 Test - Integration')
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
