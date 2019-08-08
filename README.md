# 1. Configuration file (default: config/contentsets.json)
    For a single content set, the configuration information below for job status monitoring are supplied in json format:
    • Content Set name
    • Mailbox address
    • Counts for FULL Report
    • All the pipelines involved
    • Environment identification string
    • Project Namespace

![alt text](https://github.com/Vincent-Dai-188/VinCodeRepo/blob/master/pic-1.png)

# 2. Work directories
    • Root directory: /dscat/utils_monitor
    • Directory for configuration files:  /dscat/utils_monitor/config
        - contentsets_%CONTENTSET%.json
    • Directory for html templates (e-mail): /dscat/utils_monitor/html_template
    • Directory for procedure files: /var/tmp/job-monitor_<TIMESTAMP>-XXXX
        For example: /var/tmp/job-monitor_1563860346-M5Xi. This directory will be created automatically each time. Job status monitoring related procedure files are stored in it. By default, this directory and all the files stored in it will be removed when application finishes. With -D option, you can choose to remain this directory for debugging purpose.
    • Directory for counter files: /var/tmp/mark_job_monitor
        - full_counts_%CONTENTSET% : File to store counts for “Full Report”.
    • Error log files: /var/tmp/ errout_job_monitor_<CONTENTSET>.log
        - Record the re-directed stderr output for troubleshooting
		
<img align="right" width="100" height="100" src="https://github.com/Vincent-Dai-188/VinCodeRepo/blob/master/pic-2.png">
