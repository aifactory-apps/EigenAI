# vim:ft=ruby
Pod::Spec.new do |s|
    s.ios.deployment_target = "10.0"
    s.osx.deployment_target = "10.14"
    s.library = 'c++'

    s.name = 'EigenAI'
    s.version = "1.0.3"
    s.summary = 'AiFactory redistribution of eigen header only library'
    s.description = 'Own eigen header only library'
    s.license = { :type => 'MPL2', :file => 'LICENSE' }
    s.author = { 'Pavel Savchenkov' => 'savchenkov@aifactory.app' }
    s.homepage = 'https://aifactory.app/'

    s.source = { :git => "https://github.com/aifactory-apps/EigenAI.git", :tag => "#{s.version}" }
    s.source_files = 'Eigen_ai/**/*.{h,hpp}'
    s.public_header_files = 'Eigen_ai/**/*.{h,hpp}'
    s.header_mappings_dir = '.'
    s.preserve_paths = 'Eigen_ai//**'
    s.xcconfig = { 'HEADER_SEARCH_PATHS' => '"${PODS_ROOT}/EigenAI/Eigen_ai/"' }
end
