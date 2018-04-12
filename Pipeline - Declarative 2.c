pipeline
{
      agent none

      environment
      {
      	Skip_State = "false"
      	WKSPACE = "wt-QuickLog"
      	VIA_WKSPACE = "wt-QuickLog_TestSuite"
      	Devjob = "QuickLog-dev"
      	ProjectName = "QuickLog"
      }

  stages
  {
    stage('Dev Test')
    {
	     parallel
      {
        stage('VIA Test')
        {
	         agent any
           //{ node { label 'EDA-LA-01-edalab, dlev1143-algval'
           //} }
           steps
           {
             script
             {
               if (Skip_State == "false")
               {
          				env.RELEASE_SCOPE = 'Continue'
          				if (TestSuite_WaitforUser == 'true')
                  {
          					env.RELEASE_SCOPE = input message: 'Do you want to Continue with VIA Static Analysis Test?', ok: 'Release!',
          					parameters: [choice(name: 'RELEASE_SCOPE', choices: 'Continue\nStop', description: 'What is the VIA Test Scope?')]
          				}
                  if (env.RELEASE_SCOPE == 'Continue')
                  {
  				              //echo "${env.RELEASE_SCOPE}"
  			              try
                      {
                  			//	p4sync charset: 'none', credential: 'd1b38a63-ab5c-4bd0-a600-0886e0180394', populate: autoClean(delete: true, modtime: false, parallel: [enable: false, minbytes: '1024', minfiles: '1', threads: '4'], pin: '', quiet: true, replace: true, tidy: false), source: templateSource(wt-QuickLog)
                  				//deleteDir()
                  				//echo "VIA Static Analysis Test completed..."
                  				//bat 'C:\\Batch\\build2\\labview-cli --kill --lv-ver 2014 "C:\\Batch\\build2\\Build VIPB Spec.vi" -- "%WORKSPACE%\\QuickLog\\.vipb" %DEV% %BUILD_NUMBER% "False" "Packages\LabAutomation\Teststand\Custom Steps\Datalogging" "Configuration_Files\LabAutomation\Teststand\Datalogging" "TestStand" "NA" " "'
                  				//archiveArtifacts '*.vip,QuickLog/QuickLog.html'
                  			  //bat 'C:\\Batch\\build2\\labview-cli --kill --lv-ver 2014 "C:\\Batch\\build2\\Server Promote Build.vi" -- %RELEASE% %BATCHHOME% "Temp" "Devjob" "Package"'
                        }
  			                catch (err)
                        {
                            echo err
                        }
                			  //echo "Release package to staging server is completed..."
                              //junit '*.xml'
                    }
                    if (env.RELEASE_SCOPE == 'Stop')
                    {
                      //echo "${env.RELEASE_SCOPE}"
                      echo "VIA Tests are ignored and skipped..."
                      //Skip_State = "true"

                    }
                }

                if (Skip_State == "true")
                {
                  echo "VIA Static Analysis test ignored and skipped... "
                }
              }
			      }
		          post
              {
                failure
                {
                  echo "VIA Test failed..."
                }
			        }
          }

          stage('UTF Test')
          {
            agent
              {
                node
                {
                  label 'EDA-LA-01-edalab'
                }
              }

                  steps
                  {
                    script
                    {
                      if (Skip_State == "false")
                      {
                 				env.RELEASE_SCOPE = 'Continue'
                 				if (TestSuite_WaitforUser == 'true')
                         {
                 					env.RELEASE_SCOPE = input message: 'Do you want to Continue with UTF Dynamic Analysis Test?', ok: 'Release!',
                 					parameters: [choice(name: 'RELEASE_SCOPE', choices: 'Continue\nStop', description: 'What is the UTF Test Scope?')]
                 				}
                         if (env.RELEASE_SCOPE == 'Continue')
                         {
         				              //echo "${env.RELEASE_SCOPE}"
         			              try
                             {
                         			//	p4sync charset: 'none', credential: 'd1b38a63-ab5c-4bd0-a600-0886e0180394', populate: autoClean(delete: true, modtime: false, parallel: [enable: false, minbytes: '1024', minfiles: '1', threads: '4'], pin: '', quiet: true, replace: true, tidy: false), source: templateSource(wt-QuickLog)
                         				//deleteDir()
                         			//	echo "VIA dynamic  Analysis Test completed..."
                         				//bat 'C:\\Batch\\build2\\labview-cli --kill --lv-ver 2014 "C:\\Batch\\build2\\Build VIPB Spec.vi" -- "%WORKSPACE%\\QuickLog\\.vipb" %DEV% %BUILD_NUMBER% "False" "Packages\LabAutomation\Teststand\Custom Steps\Datalogging" "Configuration_Files\LabAutomation\Teststand\Datalogging" "TestStand" "NA" " "'
                         				//archiveArtifacts '*.vip,QuickLog/QuickLog.html'
                         				//echo 'Package Creation completed'
                                 //bat 'C:\\Batch\\build2\\labview-cli --kill --lv-ver 2014 "C:\\Batch\\build2\\Server Promote Build.vi" -- %RELEASE% %BATCHHOME% "Temp" "Devjob" "Package"'
                               }
         			                catch (err)
                               {
                                   echo err
                               }
                       			  //echo "Release package to staging server is completed..."
                                     //junit '*.xml'
                           }
                           if (env.RELEASE_SCOPE == 'Stop')
                           {
                             //echo "${env.RELEASE_SCOPE}"
                             echo "UTF dynamic tests are ignored and skipped..."
                             //Skip_State = "true"

                           }
                         }


                        if (Skip_State == "true")
                        {
                          echo "Unit Test dynamic Analysis test ignored and skipped..."
                        }
                      }
        			      }
        		  post
              {
                  failure
                  {
                      echo "UTF test failed..."
                  }
              }
            }
        }
      }


  stage('Build')
  {
      agent any
      //{ node { label 'EDA-LA-01-edalab, dlev1143-algval'

      //} }
      steps
      {
        script
        {
			       if (Skip_State == "false")
             {
        				env.RELEASE_SCOPE = 'Continue'
        				if (Build_WaitforUser == 'true')
                {
        					env.RELEASE_SCOPE = input message: 'Do you want to Continue with Package Building?', ok: 'Release!',
        					parameters: [choice(name: 'RELEASE_SCOPE', choices: 'Continue\nStop', description: 'What is the release scope?')]
        				}
                if (env.RELEASE_SCOPE == 'Continue')
                {
				              //echo "${env.RELEASE_SCOPE}"
			              try
                    {
                			//	p4sync charset: 'none', credential: 'd1b38a63-ab5c-4bd0-a600-0886e0180394', populate: autoClean(delete: true, modtime: false, parallel: [enable: false, minbytes: '1024', minfiles: '1', threads: '4'], pin: '', quiet: true, replace: true, tidy: false), source: templateSource(wt-QuickLog)
                				//deleteDir()
                			//	echo "P4v - Sync - Package Suite Completed..."
                				//bat 'C:\\Batch\\build2\\labview-cli --kill --lv-ver 2014 "C:\\Batch\\build2\\Build VIPB Spec.vi" -- "%WORKSPACE%\\QuickLog\\.vipb" %DEV% %BUILD_NUMBER% "False" "Packages\LabAutomation\Teststand\Custom Steps\Datalogging" "Configuration_Files\LabAutomation\Teststand\Datalogging" "TestStand" "NA" " "'
                				//archiveArtifacts '*.vip,QuickLog/QuickLog.html'
                		//		echo 'Package Creation completed'
                        //bat 'C:\\Batch\\build2\\labview-cli --kill --lv-ver 2014 "C:\\Batch\\build2\\Server Promote Build.vi" -- %RELEASE% %BATCHHOME% "Temp" "Devjob" "Package"'
                      }
			                catch (err)
                      {
                          echo err
                      }
              			  //echo "Release package to staging server is completed..."
                            //junit '*.xml'
                  }
                  if (env.RELEASE_SCOPE == 'Stop')
                  {
                    //echo "${env.RELEASE_SCOPE}"
                    echo "Package Creation are ignored and skipped..."
                    //Skip_State = "true"

                  }
                }

      		  if (Skip_State == "true")
            {
                  echo "Package Creation are ignored and skipped..."
            }
          }
      }
      post
        {
          failure
          {
            echo "Build Step Failed..."
          }
        }
    }


    stage('Deploy to Dev')
    {
      agent any
      //{ node { label 'EDA-LA-01-edalab, dlev1143-algval'

      //} }

      steps
      {
        script
        {
			      if (Skip_State == "false")
            {
				        env.RELEASE_SCOPE = 'Continue'
				        if (DeploytoDev_WaitforUser == 'true')
                {
					         env.RELEASE_SCOPE = input message: 'Do you want to Continue with Deployment Process to Beta Server?', ok: 'Release!',
					         parameters: [choice(name: 'RELEASE_SCOPE', choices: 'Continue\nStop', description: 'What is the release scope?')]
				        }
                if (env.RELEASE_SCOPE == 'Continue')
                {
                  echo "${env.RELEASE_SCOPE}"
                  try
                  {

              				//fileOperations([fileCopyOperation(excludes: '', flattenFiles: false, includes: '*.vip', targetLocation: '\\\\xle3090dm41\\ESD\\LABSYNC\\Packages\\LabAutomation\\Teststand\\Custom Steps\\Datalogging')])
              				//fileOperations([fileCopyOperation(excludes: '', flattenFiles: false, includes: '*.html', targetLocation: '\\\\xle3090dm41\\ESD\\LABSYNC\\Configuration_Files\\LabAutomation\\Teststand\\Datalogging')])

              				//bat 'C:\\Batch\\build2\\labview-cli --kill --lv-ver 2014 "C:\\Batch\\master\\Generate Master XML.vi" -- "xle3090dm41"'
				              echo 'Master File Creation in DM41 is completed'
                  }
			            catch (err)
                  {
                    echo err
                  }
			                echo "Release package to Beta server is completed..."
                      //junit '*.xml'
			            if (BetaSystemTest_WaitforUser == 'true')
                  {
                    env.RELEASE_SCOPE = input message: 'Do you want to Continue with System test on Beta package?', ok: 'Release!',
                    parameters: [choice(name: 'RELEASE_SCOPE', choices: 'Continue\nStop', description: 'What is the release scope?')]
					        }
                }
                if (env.RELEASE_SCOPE == 'Stop')
                {
                    //echo "${env.RELEASE_SCOPE}"
                    echo "Release package to Beta server is ignored and skipped..."
                    //Skip_State = "true"
                }
              }
              if (Skip_State == "true")
              {
                echo "Release package to Beta server is ignored and skipped..."
              }
          }
      }
    }

    stage('Beta System Test')
    {
      parallel
      {
        stage('Qmetry Test')
        {
      			agent any
      			//{ node { label 'EDA-LA-01-edalab, dlev1143-algval'

      			//} }
            steps
            {
                script
                {
                    if (Skip_State == "false")
                    {
                        env.RELEASE_SCOPE = 'Continue'
                        if (BetaSystemTest_WaitforUser == 'true')
                        {
                           env.RELEASE_SCOPE = input message: 'Do you want to Continue with Deployment Process to Beta Server?', ok: 'Release!',
                           parameters: [choice(name: 'RELEASE_SCOPE', choices: 'Continue\nStop', description: 'What is the release scope?')]
                        }

                        if (env.RELEASE_SCOPE == 'Continue')
                        {
                            //echo "${env.RELEASE_SCOPE}"
                            //p4sync charset: 'none', credential: 'd1b38a63-ab5c-4bd0-a600-0886e0180394', populate: autoClean(delete: true, modtime: false, parallel: [enable: false, minbytes: '1024', minfiles: '1', threads: '4'], pin: '', quiet: true, replace: true, tidy: false), source: templateSource(wt-QuickLog)
                            try
                            {
                                //bat 'C:\\Batch\\build2\\labview-cli --kill --lv-ver 2014 "C:\\Batch\\build2\\Execute VI Tests.vi" -- "%WORKSPACE%\\Datalogging\\Test\\Test Sequences.vi"'
                            }
                            catch (err)
                            {
                              echo err
                            }

                            try
                            {
                                //bat 'C:\\Batch\\build2\\labview-cli --kill --lv-ver 2014 "C:\\Batch\\build2\\Execute VI Tests.vi" -- "%WORKSPACE%\\QuickLog\\UTF\\Run Tests.vi"'
                            }
                            catch (err)
                            {
                              echo err
                            }
				                    echo "Qmetry test on Dev package in Beta server is completed..."
                            //junit '*.xml'

                          }
                      if (env.RELEASE_SCOPE == 'Stop')
                      {
                          //echo "${env.RELEASE_SCOPE}"
                          echo "Qmetry test on Dev package in Beta server is ignored and skipped..."
                          //Skip_State = "true"
                      }
                    }
                    if (Skip_State == "true")
                    {
                      echo "Qmetry test on Dev package in Beta server is ignored and skipped..."
                    }
                }
              }
          }

        stage('LabSync Test')
        {
      			agent any
      			//{ node { label 'EDA-LA-01-edalab, dlev1143-algval'

      			//} }
            steps
            {
                script
                {
                  if (Skip_State == "false")
                  {
                      env.RELEASE_SCOPE = 'Continue'
                      if (BetaSystemTest_WaitforUser == 'true')
                      {
                         env.RELEASE_SCOPE = input message: 'Do you want to Continue with Deployment Process to Beta Server?', ok: 'Release!',
                         parameters: [choice(name: 'RELEASE_SCOPE', choices: 'Continue\nStop', description: 'What is the release scope?')]
                      }

                      if (env.RELEASE_SCOPE == 'Continue')
                      {
                        //echo "${env.RELEASE_SCOPE}"
                        //p4sync charset: 'none', credential: 'd1b38a63-ab5c-4bd0-a600-0886e0180394', populate: autoClean(delete: true, modtime: false, parallel: [enable: false, minbytes: '1024', minfiles: '1', threads: '4'], pin: '', quiet: true, replace: true, tidy: false), source: templateSource(wt-QuickLog)
                        try
                        {
                          //bat 'C:\\Batch\\build2\\labview-cli --kill --lv-ver 2014 "C:\\Batch\\build2\\Execute VI Tests.vi" -- "%WORKSPACE%\\Datalogging\\Test\\Test Sequences.vi"'
                        }
                        catch (err)
                        {
                          echo err
                        }
                        try
                        {
                          //bat 'C:\\Batch\\build2\\labview-cli --kill --lv-ver 2014 "C:\\Batch\\build2\\Execute VI Tests.vi" -- "%WORKSPACE%\\QuickLog\\UTF\\Run Tests.vi"'
                        }
                        catch (err)
                        {
                          echo err
                        }
      				      echo "Labsync test on Dev package in Beta server is completed..."
                    //junit '*.xml'
                    }
                    if (env.RELEASE_SCOPE == 'Stop')
                    {
                        //echo "${env.RELEASE_SCOPE}"
                        echo "LabSync test on Dev package in Beta server is ignored and skipped..."
                        //Skip_State = "true"
                    }
                  }
                  if (Skip_State == "true")
                  {
                    echo "LabSync test on Dev package in Beta server is ignored and skipped..."
                  }
                }
              }
            }
          }
        }

      stage('Deploy to Staging')
      {
    			agent any
    			//{ node { label 'EDA-LA-01-edalab, dlev1143-algval'

    			//} }
          steps
          {
            script
            {
              if (Skip_State == 'false')
              {
          			  env.RELEASE_SCOPE = 'Continue'
                  if (DeploytoStaging_WaitforUser == 'true')
                  {
          				  env.RELEASE_SCOPE = input message: 'Do you want to Continue with deployment Process to Staging?', ok: 'Release!',
                    parameters: [choice(name: 'RELEASE_SCOPE', choices: 'Continue\nStop', description: 'What is the release scope?')]
                  }
                  if (env.RELEASE_SCOPE == 'Continue')
                  {
                      echo "${env.RELEASE_SCOPE}"
                      try
                      {
                          //bat '%BATCHHOME%\\mirror\\mirror.bat "\\\\xle3090dm44\\ESD\\LABSYNC" "E:\\ESD\\LABSYNC"'
                				  //fileOperations([fileCopyOperation(excludes: '', flattenFiles: false, includes: '*.vip', targetLocation: 'C:\\Batch\\Temp\\DEMO-QuickLog-DPipeline')])
                				  //"%BATCHHOME%\build2\labview-cli" --kill --lv-ver 2014 "%BATCHHOME%\build2\Server Promote Build.vi" -- %RELEASE% %BATCHHOME% "Temp" "DEMO-QuickLog-DPipeline" "QuickLog"
                				  echo "Deployment to Staging is Completed..."
                				  //fileOperations([fileCopyOperation(excludes: '', flattenFiles: false, includes: '*.vip', targetLocation: '\\\\xle3090dm44\\ESD\\LABSYNC\\Packages\\LabAutomation\\Teststand\\Custom Steps\\Datalogging')])
                				  //fileOperations([fileCopyOperation(excludes: '', flattenFiles: false, includes: '*.html', targetLocation: '\\\\xle3090dm44\\ESD\\LABSYNC\\Configuration_Files\\LabAutomation\\Teststand\\Datalogging')])
                				  //bat 'C:\\Batch\\build2\\labview-cli --kill --lv-ver 2014 "C:\\Batch\\master\\Generate Master XML.vi" -- "xle3090dm44"'
                				  echo 'Master File Creation in DM44 is completed'
                        }
                        catch (err)
                        {
                          echo err
                        }
  				              if (StagingSystemTest_WaitforUser == 'true')
                        {
                            env.RELEASE_SCOPE = input message: 'Do you want to Continue with Qmetry test on Staging server package?', ok: 'Release!',
                            parameters: [choice(name: 'RELEASE_SCOPE', choices: 'Continue\nStop', description: 'What is the release scope?')]
  					            }
                    }
                    if (env.RELEASE_SCOPE == 'Stop')
                    {
                      //echo "${env.RELEASE_SCOPE}"
                      echo "Deployment to Staging is ignored and skipped..."
                      //Skip_State = "true"
                    }
                }
			              if (Skip_State == "true")
                    {
                      echo "Deployment to Staging is ignored and skipped..."
                    }
			       }
          }
      }

      stage('Staging System Test')
      {
          parallel
          {
              stage('Qmetry Test')
              {
          			agent any
          			//{ node { label 'EDA-LA-01-edalab, dlev1143-algval'

          			//} }
              steps
              {
                  script
                  {
                      if (Skip_State == "false")
                      {
                          env.RELEASE_SCOPE = 'Continue'
                          if (StagingSystemTest_WaitforUser == 'true')
                          {
                             env.RELEASE_SCOPE = input message: 'Do you want to Continue with Deployment Process to Beta Server?', ok: 'Release!',
                             parameters: [choice(name: 'RELEASE_SCOPE', choices: 'Continue\nStop', description: 'What is the release scope?')]
                          }
                          if (env.RELEASE_SCOPE == 'Continue')
                          {
                              //echo "${env.RELEASE_SCOPE}"
                            //  p4sync charset: 'none', credential: 'd1b38a63-ab5c-4bd0-a600-0886e0180394', populate: autoClean(delete: true, modtime: false, parallel: [enable: false, minbytes: '1024', minfiles: '1', threads: '4'], pin: '', quiet: true, replace: true, tidy: false), source: templateSource(wt-QuickLog)
                              try
                              {
                                //bat 'C:\\Batch\\build2\\labview-cli --kill --lv-ver 2014 "C:\\Batch\\build2\\Execute VI Tests.vi" -- "%WORKSPACE%\\Datalogging\\Test\\Test Sequences.vi"'
                              }
                              catch (err)
                              {
                                echo err
                              }
                              try
                              {
                                  //bat 'C:\\Batch\\build2\\labview-cli --kill --lv-ver 2014 "C:\\Batch\\build2\\Execute VI Tests.vi" -- "%WORKSPACE%\\QuickLog\\UTF\\Run Tests.vi"'
                              }
                              catch (err)
                              {
                                  echo err
                              }
				                      echo "Qmetry test on Release package in Staging server is completed..."
                              //junit '*.xml'
                            }
                            if (env.RELEASE_SCOPE == 'Stop')
                            {
                              //echo "${env.RELEASE_SCOPE}"
                              echo "Qmetry test on Release package in Staging server is ignored and skipped..."
                              //Skip_State = "true"
                            }
                      }
                      if (Skip_State == "true")
                      {
                        echo "Qmetry test on Release package in Staging server is ignored and skipped..."
                      }
                    }
                  }
                }

        stage('LabSync Test')
        {
      			agent any
      			//{ node { label 'EDA-LA-01-edalab, dlev1143-algval'
      			//} }
            steps
            {
                script
                {
                    if (Skip_State == "false")
                    {
                        env.RELEASE_SCOPE = 'Continue'
                        if (StagingSystemTest_WaitforUser == 'true')
                        {
                           env.RELEASE_SCOPE = input message: 'Do you want to Continue with Deployment Process to Beta Server?', ok: 'Release!',
                           parameters: [choice(name: 'RELEASE_SCOPE', choices: 'Continue\nStop', description: 'What is the release scope?')]
                        }
                        if (env.RELEASE_SCOPE == 'Continue')
                        {
                            //echo "${env.RELEASE_SCOPE}"
                          //  p4sync charset: 'none', credential: 'd1b38a63-ab5c-4bd0-a600-0886e0180394', populate: autoClean(delete: true, modtime: false, parallel: [enable: false, minbytes: '1024', minfiles: '1', threads: '4'], pin: '', quiet: true, replace: true, tidy: false), source: templateSource(wt-QuickLog)
                            try
                            {
                                //bat 'C:\\Batch\\build2\\labview-cli --kill --lv-ver 2014 "C:\\Batch\\build2\\Execute VI Tests.vi" -- "%WORKSPACE%\\Datalogging\\Test\\Test Sequences.vi"'
                            }
                            catch (err)
                            {
                              echo err
                            }
                            try
                            {
                              //bat 'C:\\Batch\\build2\\labview-cli --kill --lv-ver 2014 "C:\\Batch\\build2\\Execute VI Tests.vi" -- "%WORKSPACE%\\QuickLog\\UTF\\Run Tests.vi"'
                            }
                            catch (err)
                            {
                              echo err
                            }
				                    echo "Labsync test on Release package in Staging server is completed..."
                            //junit '*.xml'
                          }
                          if (env.RELEASE_SCOPE == 'Stop')
                          {
                            //echo "${env.RELEASE_SCOPE}"
                            echo "LabSync test on Release package in Staging server is ignored and skipped..."
                            //Skip_State = "true"
                          }
                    }
                    if (Skip_State == "true")
                    {
                      echo "LabSync test on Release package in Staging server is ignored and skipped..."
                    }
                }
              }
            }
          }
    }


    stage('Production')
    {
        parallel
        {
          stage('Replication')
          {
        			agent any
        			//{ node { label 'EDA-LA-01-edalab, dlev1143-algval'

        			//} }
              steps
              {
                  script
                  {
                    if (Skip_State == 'false')
                    {
      			             env.RELEASE_SCOPE = 'Continue'
                         if (Replicate_WaitforUser == 'true')
                         {
                            env.RELEASE_SCOPE = input message: 'Do you want to Continue with Replication Process?', ok: 'Release!',
                            parameters: [choice(name: 'RELEASE_SCOPE', choices: 'Continue\nStop', description: 'What is the release scope?')]
                         }
                         if (env.RELEASE_SCOPE == 'Continue')
                         {
                            echo "${env.RELEASE_SCOPE}"
                            try
                            {
                              //bat '%BATCHHOME%\\mirror\\mirror.bat "\\\\xle3090dm44\\ESD\\LABSYNC" "E:\\ESD\\LABSYNC"'
                            }
                            catch (err)
                            {
                              echo err
                            }
                            echo "Replication from staging server to Production is Completed..."
                          }
                          if (env.RELEASE_SCOPE == 'Stop')
                          {
                              //echo "${env.RELEASE_SCOPE}"
                              echo "Replication from staging server to Production is ignored and skipped..."
                              //Skip_State = "true"
                          }
                    }
			              if (Skip_State == "true")
                    {
                      echo "Replication from staging server to Production is ignored and skipped..."
                    }
			           }

               }
          }
       }
    }
  }
}
